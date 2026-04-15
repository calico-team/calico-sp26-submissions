def solve(N: int, S1: list[str], S2: list[str]) -> tuple[int, int]:
    """
    Return the maximal and minimal volume of the shape (in that order)
    
    N: max dimensions of shape
    S1: projection (shadow) in X-Z plane
    S2: projection (shadow) in Y-Z plane
    """
    box = [[[1] * N for _ in range(N)] for _ in range(N)]

    # chekcing max volume

    # let S1 on x plane
    for i in range(N):
        chrs = list(S1[i])
        for ch in range(N):
            if chrs[ch] == '.':
                for k in range(N):
                    box[k][i][ch] = 0

    # let S2 on z plane
    for i in range(N):
        chrs = list(S2[i])
        for ch in range(N):
            if chrs[ch] == '.':
                for k in range(N):
                    box[ch][i][k] = 0

    countmax = 0
    for i in range(N):
        for j in range(N):
            for k in range(N):
                if box[i][j][k] == 1:
                    countmax += 1

    # count min vol, turn 1 to intersection of S1 and S2, and 0 to others
    countmin = 0
    for i in range(N):
        s1chrs = list(S1[i])
        s2chrs = list(S2[i])
        for j in range(N):
            if s1chrs[j] == '#' and s2chrs[j] == '#':
                for k in range(N):
                    box[i][j][k] = 1

    countmin = 0
    for i in range(N):
        s1chrs = S1[i].count('#')
        s2chrs = S2[i].count('#')
        countmin += max(s1chrs, s2chrs)

    return countmax, countmin

def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        S1 = [input() for _ in range(N)]
        S2 = [input() for _ in range(N)]
        print(*solve(N, S1, S2))


if __name__ == '__main__':
    main()
