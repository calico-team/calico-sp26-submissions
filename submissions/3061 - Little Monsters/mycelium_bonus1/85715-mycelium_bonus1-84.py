from collections import deque
def solve():
    grassx, grassy, misx, misy = map(int, input().split())

    grass = deque([(grassx, grassy)])
    mis = deque([(misx, misy)])
    numMis = 0
    tick = 1

    grassloc = {(grassx, grassy)}
    misloc = {(misx, misy)}

    dirs = ((1, 0), (-1, 0), (0, 1), (0, -1))

    while True:
        if tick % 2 == 0:
            for _ in range(len(grass)):

                r, c = grass.popleft()

                for dr, dc in dirs:
                    nr, nc = r + dr, c + dc

                    if ((nr, nc) not in grassloc) and ((nr, nc) not in misloc):
                        grassloc.add((nr, nc))
                        grass.append((nr, nc))

        if tick % 7 == 0:
            for _ in range(len(mis)):
                numMis+=1
                r, c = mis.popleft()

                for dr, dc in dirs:
                    nr, nc = r + dr, c + dc

                    if ((nr, nc) not in grassloc) and ((nr, nc) not in misloc):
                        misloc.add((nr, nc))
                        mis.append((nr, nc))
        tick+=1
        
        #test
        #for i in range(5, -5, -1):
        #    cur = []
        #    for j in range(-5, 5):
        #        if (i, j) in grassloc:
        #            cur.append("G")
        #        elif (i, j) in misloc:
        #            cur.append("M")
        #        else:
        #            cur.append("-")
        #    print(cur)
        #print()
        #

        if len(mis) == 0:
            return (numMis)

for _ in range(int(input())):
    print(solve())            





