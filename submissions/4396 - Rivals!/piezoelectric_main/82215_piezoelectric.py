n=int(input())
for i in range(n):
    lwer=input().split(" ")
    l=int(lwer[0])
    w=int(lwer[1])
    e=int(lwer[2])
    r=int(lwer[3])
    p=(l+w)*2
    lap=p*r
    answer=e//lap
    print(answer)
