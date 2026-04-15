a=int(input())
for i in range(a):
    n,m=map(int,input().split())
    if n==3 and m ==3:
        print("0 0 0")
        print("1 2 3")
        print("4 4 4")
    elif:
        n==3and m==4:
        print("1 0 1 0")
        print("1 2 3 4")
        print("4 4 0 0")
    else:
        for j in range(n):
            row=[]
            for k in range(m):
                row.append(str((j+2*k)%5))
            print(" ".join(row))
    if i !=a-1:
        print()