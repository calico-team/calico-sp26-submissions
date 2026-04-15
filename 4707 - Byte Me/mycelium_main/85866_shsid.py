t = int(input())

def solve(g1, g2, m1, m2):
    coor_g = set([(g1, g2)])
    coor_m = set([(m1, m2)])
    changes = True
    count = 1
    
    while True:
        ncg = set()
        ncm = set()
        if count %14 == 0 :
            changes =False
            for x,y in coor_g:
                nc = [(x,y+1),(x,y-1),(x-1,y),(x+1,y)]
                for z,a in nc:
                    if (z,a) not in coor_m:
                        ncg.add((z,a))
                        changes = True
            for x,y in coor_m:
                nc = [(x,y+1),(x,y-1),(x-1,y),(x+1,y)]
                for z,a in nc:
                    if (z,a) not in coor_g:
                        ncm.add((z,a))
                        changes=True
        if count %7 == 0 :
            changes =False
            for x,y in coor_m:
                nc = [(x,y+1),(x,y-1),(x-1,y),(x+1,y)]
                for z,a in nc:
                    if (z,a) not in coor_g:
                        ncm.add((z,a))
                        changes=True
        if count % 2 == 0:
            for x,y in coor_g:
                nc = [(x,y+1),(x,y-1),(x-1,y),(x+1,y)]
                for z,a in nc:
                    if (z,a) not in coor_m:
                        ncg.add((z,a))
        count += 1
        if changes is False:
            return len(coor_m)

for _ in range(t):
    g1, g2, m1, m2 = map(int, input().split())
    print(solve(g1, g2, m1, m2))