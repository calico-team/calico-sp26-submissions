for _ in range(int(input())):
    n = int(input())
    a = [list(input()) for i in range(n)]
    b = [list(input()) for i in range(n)]

    mx = n**3
    mn = 0
    
    for i in range(n):
        row = a[i].count(".")
        col = b[i].count(".")
        
        mx -= row*n + col*n
        mx += row*col

        mn += max(n-row,n-col)

    print(mx,mn)
    
