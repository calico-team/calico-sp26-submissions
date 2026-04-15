for i in range(int(input())):
    x, y, a, b = map(int, input().split())
    mfr = [[a - 1, b], [a + 1, b], [a, b + 1], [a, b - 1]]
    gfr = [[x - 1, y], [x + 1, y], [x, y + 1], [x, y - 1]]
    pos = {}
    pos[a] = {}
    pos[x] = {}
    pos[a][b] = 0
    pos[x][y] = 0
    marea = 1
    nm = -1
    tick = 0
    while len(mfr) > 0:
        tick += 1
        if tick % 2 == 0:
            tfr = gfr[:]
            gfr = []
            for i in tfr:
                if not (i[0] in pos):
                    pos[i[0]] = {}
                if not (i[1] in pos[i[0]]):
                    pos[i[0]][i[1]] = 0
                    gfr.append([i[0] - 1, i[1]])
                    gfr.append([i[0] + 1, i[1]])
                    gfr.append([i[0], i[1] - 1])
                    gfr.append([i[0], i[1] + 1])
        if tick % 7 == 0:
            nm = marea
            lfr = mfr[:]
            mfr = []
            for i in lfr:
                if not i[0] in pos:
                    pos[i[0]] = {}
                if not (i[1] in pos[i[0]]):
                    pos[i[0]][i[1]] = 0
                    mfr.append([i[0] - 1, i[1]])
                    mfr.append([i[0] + 1, i[1]])
                    mfr.append([i[0], i[1] - 1])
                    mfr.append([i[0], i[1] + 1])
                    marea += 1
    print(marea)