import sys
import time
from math import log,exp
from array import array

def main():
    t0 = time.time()
    data=sys.stdin.buffer.read()

    #fast int parser
    idx = 0
    def rd():
        nonlocal idx
        while data[idx]<48:idx+=1
        num = 0
        while idx<len(data)and data[idx]>=48:
            num=num*10+data[idx]-48
            idx+=1
        return num

    n = rd();m = rd();d = rd()

    #typed arrays:H=uint16(n<=4000,W<=1000),I=uint32(V<=1e9)
    R=array('H',[0]*m)
    C=array('H',[0]*m)
    V=array('I',[0]*m)
    W=array('H',[0]*m)
    for i in range(m):
        R[i]=rd()-1
        C[i]=rd()-1
        V[i]=rd()
        W[i]=rd()
    del data

    if d>=m:
        sys.stdout.write(' '.join(['1']*n)+'\n')
        sys.stdout.write(str(m)+' '+' '.join(str(i) for i in range(1,m+1))+'\n')
        return

    #build CSR adjacency storing(ci,oi)pairs
    deg = array('i',[0]*n)
    for i in range(m):
        deg[R[i]]+=1;deg[C[i]]+=1
    adj_ptr = array('i',[0]*(n+1))
    for j in range(n):
        adj_ptr[j+1]=adj_ptr[j]+deg[j]
    del deg
    adj_ci = array('i',[0]*(2*m))
    adj_oi = array('H',[0]*(2*m))
    cur = array('i',adj_ptr[:n])
    for i in range(m):
        r=R[i];c= C[i]
        adj_ci[cur[r]]=i;adj_oi[cur[r]]=c;cur[r]+=1
        adj_ci[cur[c]]=i;adj_oi[cur[c]]=r;cur[c]+=1
    del cur

    #init:weighted geometric mean in log-space
    log_v = array('d',[log(V[i])if V[i]>0 else 0.0 for i in range(m)])

    x=[0.0]*n;ws=[0.0]*n
    for i in range(m):
        wlv=W[i]*log_v[i]
        x[R[i]]+=wlv;ws[R[i]]+=W[i]
        x[C[i]]+=wlv;ws[C[i]]+=W[i]
    for j in range(n):
        if ws[j]>0:x[j]/=ws[j]*2

    #gauss-seidel in log-space
    active = bytearray(b'\x01'*m)
    for gs in range(3):
        if time.time()-t0>2.0:break
        for j in range(n):
            st=adj_ptr[j];en=adj_ptr[j+1]
            if st==en:continue
            num=0.0;den=0.0
            for ci,oi in zip(adj_ci[st:en],adj_oi[st:en]):
                if active[ci]:
                    num+=W[ci]*(log_v[ci]-x[oi])
                    den+=W[ci]
            if den>0:
                val=num/den
                if val>21:val=21.0
                elif val<-21:val=-21.0
                x[j]=val

    #to integers
    a=[0]*n
    for j in range(n):
        xj=x[j]
        if xj>20.7:a[j]=1000000000
        elif xj<-20:a[j]=1
        else:a[j]=max(1,min(1000000000,int(exp(xj)+0.5)))

    #Discard
    pens = array('d',[0.0]*m)
    def update_discard():
        for i in range(m):
            prod=a[R[i]]*a[C[i]]
            vi=V[i]
            pens[i]=W[i]*abs(prod-vi)/vi if vi else W[i]*prod
        if d>0:
            order=sorted(range(m),key=pens.__getitem__,reverse=True)
            active[:]=b'\x01'*m
            for k in range(min(d,m)):
                active[order[k]]=0

    update_discard()

    #coord descent with weighted median
    for cd in range(30):
        if time.time()-t0>9.0:break
        changed=False
        for j in range(n):
            if j%200 ==0 and time.time()-t0>9.0:break
            st=adj_ptr[j];en=adj_ptr[j+1]
            if st==en:continue
            ci_sl=adj_ci[st:en];oi_sl=adj_oi[st:en]

            items=[]
            for ci,oi in zip(ci_sl,oi_sl):
                if not active[ci]:continue
                other=a[oi];vi=V[ci]
                if other<=0 or vi==0:continue
                items.append((vi/other,W[ci]*other/vi))
            if not items:continue

            items.sort()
            total_w=0.0
            for _,wt in items:total_w+=wt
            half = total_w * 0.5; cum=0.0; med = items[0][0]
            for t,wt in items:
                cum += wt
                if cum >=half:med=t;break

            f=int(med)
            if f<1:f=1
            if f>1000000000:f=1000000000
            c=f+1 if f<1000000000 else f

            old=a[j]
            seen=set()
            cands=[]
            for v in(f-1,f,c,old-1,old+1):
                if 1<=v<=1000000000 and v!=old and v not in seen:
                    cands.append(v);seen.add(v)

            if not cands:continue

            def pen_of(val):
                p=0.0
                for ci,oi in zip(ci_sl,oi_sl):
                    if active[ci]:
                        vi=V[ci]
                        if vi:p+=W[ci]*abs(val*a[oi]-vi)/vi
                        else:p+=W[ci]*val*a[oi]
                return p

            best_pen=pen_of(old);best=old
            for cand in cands:
                p=pen_of(cand)
                if p<best_pen:best_pen=p;best=cand

            if best!=old:
                a[j]= best;changed=True

        if not changed:break
        if time.time()-t0>9.0:break
        update_discard()

    #Final discard
    for i in range(m):
        prod= a[R[i]]*a[C[i]]
        vi=V[i]
        pens[i] =W[i]*abs(prod-vi)/vi if vi else W[i]*prod

    if d>0:
        order= sorted(range(m),key=pens.__getitem__,reverse=True)
        disc= sorted(order[:min(d,m)])
    else:
        disc =[]

    disc =[i for i in disc if pens[i]>0]
    disc.sort()

    out =[]
    out.append(' '.join(map(str, a)))
    d1= [i+1 for i in disc]
    if d1:out.append(str( len(d1))+' '+' '.join(map(str, d1)))
    else:out.append('0')
    sys.stdout.write('\n'.join(out)+'\n')

main()
