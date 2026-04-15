#2D dp?
#binsearch (find min D) + psums (O1 for available seats)
# ily mommybunny
# Dear MommyBunny,
#   Here is another letter from your beloved team, ASK.
# We want to express our appreciation towards your relentless dedication towards CALICO and our team. And me. 
# coderbunny, please call 331-220-4772💗💗😻🥰
T = int(input())
for test in range(T):
    CoderBunny, M, K = map(int, input().split())
    #for i in range(CoderBunny):
    #    grid = [input().strip()]
    
    grid = []
    for i in range(CoderBunny):
        grid.append(input().strip())

    coderbunny_gyatt = CoderBunny+M-1
    psums = [[0]*(coderbunny_gyatt+1) for _ in range(coderbunny_gyatt+1)]
    #for SaltyRice in range(CoderBunny):
    #    for j in range(M):
    #        if grid[SaltyRice][j] == '-':
    #            psums[SaltyRice][j] += psums[SaltyRice-1][j] + psums[SaltyRice][j-1] - psums[SaltyRice-1][j-1]
    
    for SaltyRice in range(CoderBunny):
        for j in range(M):
            if grid[SaltyRice][j] == '-':
                psums[SaltyRice+j+1][SaltyRice - j + M] += 1

    for i in range(1, coderbunny_gyatt+1):
        for j in range(1, coderbunny_gyatt+1):
            psums[i][j] += psums[i-1][j] + psums[i][j-1] - psums[i-1][j-1]

    #bineary search on mommybunny

    alfphaderp, high = 0, coderbunny_gyatt
    while alfphaderp < high:
        in_coderbunny_gyatt = (alfphaderp + high) // 2
        sonit = False
        for row in range(coderbunny_gyatt - in_coderbunny_gyatt):
            for col in range(coderbunny_gyatt - in_coderbunny_gyatt):
                if psums[row+in_coderbunny_gyatt + 1][col+in_coderbunny_gyatt+1]-psums[row][col+in_coderbunny_gyatt+1]-psums[row+in_coderbunny_gyatt+1][col]+psums[row][col] >= K:
                    sonit = True
                    break
            if sonit:
                break
        if sonit:
            high = in_coderbunny_gyatt
        else:
            alfphaderp = in_coderbunny_gyatt + 1
    
    bestR = bestC =0
    done = False
    for r in range(coderbunny_gyatt - alfphaderp):
        for c in range(coderbunny_gyatt - alfphaderp):
            if psums[r+alfphaderp + 1][c+alfphaderp+1]-psums[r][c+alfphaderp+1]-psums[r+alfphaderp+1][c]+psums[r][c] >= K:
                bestR, bestC = r,c
                done = True
                break
        if done:
            break
    ily = []
    for row in range(CoderBunny):
        left = 0
        for column in range(M):
            if grid[row][column] == '#':
                left += 1
                continue
            node1 = row + column
            node2 = row - column + (M-1)
            if bestR <= node1 <= bestR + alfphaderp and bestC <= node2 <= bestC + alfphaderp:
                aura = min(left, grid[row][column+1:].count('#'))
                ily.append((aura, row, column))
    ily.sort()
    for a, r, c in ily[:K]:
        print(r, c)