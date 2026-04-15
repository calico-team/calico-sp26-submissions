for _ in range(int(input())):
    n,m = [int(i) for i in input().split()]
    ans = [[0 for i in range(m)] for j in range(n)]
    for i in range(n):
        for j in range(m):
            ans[i][j] = (2*i+j)%5 
    for i in ans:
        print(*i)