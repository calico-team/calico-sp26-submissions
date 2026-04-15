t=int(input())
answer=[]
for i in range(t):
    an=''
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
    for bb in range(len(b)):
        for k in range(len(a)):
            if l[k]==0 and a[k]==b[bb] and w[bb]==0:
                l[k]=1
                w[bb]=1
    for c in range(len(b)):
        if w[c]!=1:
            b[c]='#'
    for j in b:
        an+=j
    answer.append(an)
for i in answer:
    print(i)
