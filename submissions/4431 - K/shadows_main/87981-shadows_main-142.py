import sys
from collections import deque

def main():
    d = sys.stdin.read().split()
    p = 0
    T = int(d[p])
    p += 1
    for _ in range(T):
        N = int(d[p])
        p += 1
        s1 = [d[p+i] for i in range(N)]; p += N
        s2 = [d[p+i] for i in range(N)]; p += N

        X, Y = [[] for _ in range(N)], [[] for _ in range(N)]
        for z in range(N):
                X[z] = [x for x in range(N) if s1[z][x] =='#']
                Y[z] = [y for y in range(N) if s2[z][y] =='#']

        mx = sum(len(x)*len(y) for x, y in zip(X, Y))
        mn = 0

        for xs, ys in zip(X, Y):
            n, m = len(xs), len(ys)
            if n == 0 or m == 0:
                continue
            adj = [list(range(m)) for _ in range (n)]
            pu = [-1] * n
            pv = [-1] * m
            dis = [O] * n
            
            def bfs():
                q = deque ()
                for u in range(n):
                    if pu[u] == - 1:
                        dis[u] = 0
                        q.append(u)
                    else:
                        dis[u] = 10**18
                res = 10**18
                while q:
                    u = q.popleft()
                    if dis [u] < res:
                        for v in adj[u]:
                            if pv[v] == -1: res = dis[u]+1
                            elif dis[pv[v]] == 10**18：
                                dis[pv[v]] = dis[u]+1
                                q. append(pv[v])
                return res != 10**18
            
            def dfs(u):
                for v in adj[u]:
                    if pv[v］ == -1 or (dis[pv[v]] == dis[u]+1 and dfs(pv[v])):
                        pu[u] = v; pv[v] = u; return 1
                dis[u] = 10**18; return O
                
            c = 0
            while bfs(():
                for u in range (n):
                      if pu[u] == - 1: c += dfs(u)
            mn += c
        print(mx, mn)
                      
if __name__ == '__main__':
    main()
