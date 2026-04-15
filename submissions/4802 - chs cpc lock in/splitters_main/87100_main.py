def gcd(a,b):
    if a>b:
        return gcd(b,a)
    if a==0:
        return b
    return gcd(b%a, a)

def add(f1, f2):
    return (f1[0]*f2[1] + f1[1]*f2[0], f1[1]*f2[1])

def simplify(f):
    g = gcd(*f)
    return (f[0]//g, f[1]//g)

def dfs(x, y, arr):
    if not (0<=x<n and 0<=y<m):
        return 'E'
    a = arr[x][y]
    while a in {'<', '>', '^', 'v'}:
        if a=='<':
            y -= 1
        elif a=='>':
            y += 1
        elif a=='^':
            x -= 1
        else:
            x += 1
        if not (0<=x<n and 0<=y<m):
            return 'E'
        a = arr[x][y]
    if a=='X':
        return a
    return (x,y)

dagmem = {}
def dag(x, y, arr):
    pos = dfs(x,y,arr)
    if pos=='X':
        return (0,1)
    elif pos=='E':
        return (1,1)
    if pos in dagmem:
        return dagmem[pos]
    x,y = pos
    nxts = []
    if x==0 or arr[x-1][y] not in {'v', '.'}:
        nxts.append((x-1,y))
    if x==n-1 or arr[x+1][y] not in {'^', '.'}:
        nxts.append((x+1,y))
    if y==0 or arr[x][y-1] not in {'>', '.'}:
        nxts.append((x,y-1))
    if y==m-1 or arr[x][y+1] not in {'<', '.'}:
        nxts.append((x,y+1))
    frac = (0,1)
    for nx,ny in nxts:
        nf = dag(nx, ny, arr)
        frac = add(frac, (nf[0], nf[1]*len(nxts)))
    frac = simplify(frac)
    dagmem[x,y] = frac
    return frac

def main():
    global m,n
    inp = input()
    n, m = map(int, inp.split())
    # n rows, m cols
    arr = [input() for _ in range(n)]
    vertices = {(0,0): 0, 'E': 1, 'X': 2}
    points = 3
    for i in range(n):
        for j in range(m):
            if arr[i][j]=='S':
                vertices[(i,j)] = points
                points += 1
    res = dag(0,0,arr)
    print(*res)
    dagmem.clear()

for tc in range(int(input())):
    main()
