t=int(input())
answer=[]
for i in range(t):
    an=''
    kk=0
    b=input()
    a=input()
    a=list(a)
    b=list(b)
    l=[]
    w=[]
    for j in range(len(a)):
        l.append(0)
    for j in range(len(b)):
        w.append(0)
    for k in range(len(a)):
        for bb in range(kk,len(b)):
            if l[k]==0 and a[k]==b[bb] and w[bb]==0:
                l[k]=1
                w[bb]=1
                kk=bb
    for c in range(len(b)):
        if w[c]!=1:
            b[c]='#'
    for j in b:
        an+=j
    answer.append(an)
for i in answer:
    print(i)
