for i in range(int(input())):
    a=int(input())
    b=input().split()
    s=""
    for j in range(a):
        if j==0:
            s=b[i]
        else:
            s=s+" "+b[i]
    print(s)
