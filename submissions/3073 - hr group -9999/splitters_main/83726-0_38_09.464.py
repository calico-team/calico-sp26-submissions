from fractions import Fraction

mp = {"v":(1,0),">":(0,1),"<":(0,-1),"^":(-1,0)}
adj = [(1,0),(-1,0),(0,1),(0,-1)]

for _ in range(int(input())):
    n,m = map(int,input().split())
    a = [list(input()) for i in range(n)]

    topo = []
    vis = [[0]*m for i in range(n)]

    def dfs(i,j):
        if a[i][j] == "S":
            for di,dj in adj:
                ni = i+di
                nj = j+dj

                if a[ni][nj] == ".":
                    continue

                if a[ni][nj] in "<>^v":
                    bruhi, bruhj = mp[a[ni][nj]]

                    if ni + bruhi == i and nj + bruhj == j:
                        continue
                    
                if vis[ni][nj]:
                    continue

                vis[ni][nj] = 1
                dfs(ni,nj)

            topo.append((i,j))
            return



        if a[i][j] == "X":
            topo.append((i,j))
            return

        di,dj = mp[a[i][j]]
        ni = i+di
        nj = j+dj

        if ni < 0 or ni >= n or nj < 0 or nj >= m:
            topo.append((i,j))
            return

        if vis[ni][nj]:
            topo.append((i,j))
            return

        vis[ni][nj] = 1
        dfs(ni,nj)

        topo.append((i,j))

    dfs(0,0)

    topo.reverse()

    dp = [[Fraction(0,1)]*m for i in range(n)]
    dp[0][0] = Fraction(1,1)

    ans = Fraction(0,1)

    for i,j in topo:
        if a[i][j] == "S":
            valid = []
            for di,dj in adj:
                ni = i+di
                nj = j+dj

                if a[ni][nj] == ".":
                    continue

                if a[ni][nj] in "<>^v":
                    bruhi, bruhj = mp[a[ni][nj]]

                    if ni + bruhi == i and nj + bruhj == j:
                        continue
                    
                valid.append((ni,nj))

            for ni,nj in valid:
                dp[ni][nj] += dp[i][j] * Fraction(1,len(valid))

            continue

        if a[i][j] == "X":
            dp[ni][nj] = 0
            continue

        di,dj = mp[a[i][j]]
        ni = i+di
        nj = j+dj

        if ni < 0 or ni >= n or nj < 0 or nj >= m:
            ans += dp[i][j]
            continue

        dp[ni][nj] += dp[i][j]

    print(ans.numerator,ans.denominator)
                
    
        
                
    
    
