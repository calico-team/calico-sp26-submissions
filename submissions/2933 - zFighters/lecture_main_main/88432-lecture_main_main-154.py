def solve(N, M, K, GRID):
    """
    N: number of rows in the lecture hall
    M: number of columns in the lecture hall
    K: number of friends who need seats
    GRID: list of N strings of length M; '#' is a blocked seat, '-' is an empty seat

    Return a list of K (row, col) tuples for the chosen seats.
    """
    av_seets = []
    for r in range(N):
        c_row = GRID[r]
        for c in range(M):
            if c_row[c] == '-':
                occ_L = c_row[:c].count('#')
                occ_R = c_row[c+1:].count('#')
                loss = min(occ_L, occ_R)
                
                av_seets.append({
                    'r': r, 
                    'c': c, 
                    'aura': loss
                })

    group_cords = []
    max_D = float('inf')
    total = float('inf')

    for anchor in av_seets:
        seed_D = []
        for other_S in av_seets:
            dist = abs(anchor['r'] - other_S['r']) + abs(anchor['c'] - other_S['c'])
            seed_D.append({
                'dist': dist,
                'aura': other_S['aura'],
                'r': other_S['r'],
                'c': other_S['c']
            })
        
        seed_D.sort(key=lambda x: (x['dist'], x['aura']))
        seleted_G = seed_D[:K]
        max_D = 0
        sum = 0
        cords = []
        
        for i in range(len(seleted_G)):
            s1 = seleted_G[i]
            sum += s1['aura']
            cords.append((s1['r'], s1['c']))
            for j in range(i + 1, len(seleted_G)):
                s2 = seleted_G[j]
                d = abs(s1['r'] - s2['r']) + abs(s1['c'] - s2['c'])
                if d > max_D:
                    max_D = d
        if max_D < max_D:
            max_D = max_D
            total = sum
            group_cords = cords
        elif max_D == max_D:
            if sum < total:
                total = sum
                group_cords = cords
                
    return group_cords


def main():
    T = int(input())
    for _ in range(T):
        N, M, K = map(int, input().split())
        GRID = []
        for _ in range(N):
            GRID.append(input().strip())
        result = solve(N, M, K, GRID)
        for r, c in result:
            print(f"{r} {c}")


if __name__ == '__main__':
    main()
