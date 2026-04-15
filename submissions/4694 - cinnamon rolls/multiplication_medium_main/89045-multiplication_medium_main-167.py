import sys
import math
import heapq
from collections import deque
from itertools import chain

def solve(N, M, D, cells):
    if M == 0:
        return [1]*N, []
    R=[c[0]-1 for c in cells]; C=[c[1]-1 for c in cells]
    V=[float(c[2]) for c in cells]; W=[float(c[3]) for c in cells]
    logV=[math.log(v) for v in V]
    if M>300000: n_ord=1; k_cands=3; cd_rounds=0
    elif M>80000: n_ord=2; k_cands=7; cd_rounds=2
    else: n_ord=2; k_cands=15; cd_rounds=8
    buckets=[[] for _ in range(1001)]
    for i in range(M): buckets[int(W[i])].append(i)
    all_orders=[list(chain.from_iterable(buckets)),list(chain.from_iterable(reversed(buckets)))][:n_ord]
    def build_spanning_tree(edge_order):
        parent=list(range(N)); rank=[0]*N
        def find(x):
            while parent[x]!=x: parent[x]=parent[parent[x]]; x=parent[x]
            return x
        def union(a,b):
            a,b=find(a),find(b)
            if a==b: return False
            if rank[a]<rank[b]: a,b=b,a
            parent[b]=a
            if rank[a]==rank[b]: rank[a]+=1
            return True
        tree=[]; nontree=[]
        for i in edge_order: (tree if union(R[i],C[i]) else nontree).append(i)
        return tree,nontree
    def bfs_assign(tree_edges):
        adj=[[] for _ in range(N)]
        for i in tree_edges: adj[R[i]].append((C[i],i)); adj[C[i]].append((R[i],i))
        x=[None]*N; color=[None]*N
        for start in range(N):
            if x[start] is None:
                x[start]=0.0; color[start]=0; q=deque([start])
                while q:
                    node=q.popleft()
                    for nb,ei in adj[node]:
                        if x[nb] is None:
                            x[nb]=logV[ei]-x[node]; color[nb]=1-color[node]; q.append(nb)
        for i in range(N):
            if x[i] is None: x[i]=0.0
            if color[i] is None: color[i]=0
        return x,color
    def eval_tc(A,B,t):
        exp=math.exp
        sz=min(500,M); step=max(1,M//sz)
        sample_bt=sorted(logV[i*step]-A[i*step]-B[i*step]*t for i in range(sz))
        c=sample_bt[len(sample_bt)//2]/2
        pens=[W[i]*abs(exp(min(max(A[i]+B[i]*t+2*c,-40.0),40.0))-V[i])/V[i] for i in range(M)]
        if D<=0: return sum(pens),pens,c
        if D>=M: return 0.0,pens,c
        top=heapq.nlargest(D,pens)
        return sum(pens)-sum(top),pens,c
    def coord_descent(x_init,active,rounds):
        x=x_init[:]
        nc=[[] for _ in range(N)]
        for i in active: nc[R[i]].append(i); nc[C[i]].append(i)
        for _ in range(rounds):
            for node in range(N):
                cons=nc[node]
                if not cons: continue
                tgts=[(logV[ci]-x[C[ci] if R[ci]==node else R[ci]],W[ci]) for ci in cons]
                tgts.sort(); tw=sum(w for _,w in tgts); cw=0.0
                for tv,wv in tgts:
                    cw+=wv
                    if cw*2>=tw: x[node]=tv; break
        return x
    def final_from_x(x):
        a=[max(1,min(10**9,round(math.exp(min(max(xi,0.0),20.7))))) for xi in x]
        pens=[(W[i]*abs(a[R[i]]*a[C[i]]-V[i])/V[i],i) for i in range(M)]
        pens.sort(reverse=True)
        d=min(D,M)
        discards=sorted(pens[j][1]+1 for j in range(d)) if d>0 else []
        return a,discards,sum(p for p,_ in pens[d:])
    def spanning_tree_solve(edge_order):
        tree,nontree=build_spanning_tree(edge_order)
        x,color=bfs_assign(tree)
        s=[1.0 if color[i]==0 else -1.0 for i in range(N)]
        A=[x[R[i]]+x[C[i]] for i in range(M)]; B=[s[R[i]]+s[C[i]] for i in range(M)]
        t_cands=[0.0]; t_tgts=[]; w_tgts=[]
        for i in nontree:
            coeff=s[R[i]]+s[C[i]]
            if coeff!=0.0: t_tgts.append((logV[i]-x[R[i]]-x[C[i]])/coeff); w_tgts.append(W[i])
        if t_tgts:
            k=min(k_cands,len(t_tgts))
            for _,tv in heapq.nlargest(k,zip(w_tgts,t_tgts)): t_cands.append(tv)
            sz=min(500,len(t_tgts)); step=max(1,len(t_tgts)//sz)
            t_s=sorted((t_tgts[i*step],w_tgts[i*step]) for i in range(sz))
            tw=sum(w for _,w in t_s); cw=0.0
            for tv,wv in t_s:
                cw+=wv
                if cw*2>=tw: t_cands.append(tv); break
            t_cands.append(t_s[len(t_s)//2][0])
        best_pen=float('inf'); best_t=0.0; best_c=0.0; best_pens=None
        for t in set(t_cands):
            pen,pens,c=eval_tc(A,B,t)
            if pen<best_pen: best_pen=pen; best_t=t; best_c=c; best_pens=pens
        x_final=[x[i]+s[i]*best_t+best_c for i in range(N)]
        if cd_rounds>0:
            if D>0 and best_pens:
                top_idx=set(i for i,_ in heapq.nlargest(D,enumerate(best_pens),key=lambda e:e[1]))
                active=[i for i in range(M) if i not in top_idx]
            else: active=list(range(M))
            x_final=coord_descent(x_final,active,cd_rounds)
        return final_from_x(x_final)
    best_a=[1]*N; best_discards=[]; best_total=float('inf')
    for order in all_orders:
        a,discards,total=spanning_tree_solve(order)
        if total<best_total: best_total=total; best_a,best_discards=a,discards
    return best_a,best_discards

def main():
    data=sys.stdin.buffer.read().split(); idx=0
    N=int(data[idx]);idx+=1; M=int(data[idx]);idx+=1; D=int(data[idx]);idx+=1
    cells=[]
    for _ in range(M):
        cells.append((int(data[idx]),int(data[idx+1]),int(data[idx+2]),int(data[idx+3]))); idx+=4
    A,discards=solve(N,M,D,cells)
    sys.stdout.write(' '.join(map(str,A))+'\n')
    sys.stdout.write(' '.join(map(str,[len(discards)]+discards))+'\n')

if __name__=='__main__':
    main()