def solve(N: int, S1: list[str], S2: list[str]) -> tuple[int, int]:
    """
    Return the maximal and minimal volume of the shape (in that order)
    
    N: max dimensions of shape
    S1: projection (shadow) in X-Z plane
    S2: projection (shadow) in Y-Z plane
    """
    max_vol=0
    min_vol=0
    
    for i in range(N):
        for j in range(N):
            if S1[i][j]=="#":
                for k in range(N):
                    if S2[j][k]=="#":
                        max_vol+=1

    
    for i in range(N):
        c1=0
        c2=0
        for j in range(N):
            if S1[j][i]=="#":
                c1+=1
            if S2[i][j]=="#":
                c2+=1
        min_vol+=max(c1, c2)
    return max_vol, min_vol


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        S1 = [input() for _ in range(N)]
        S2 = [input() for _ in range(N)]
        print(*solve(N, S1, S2))


if __name__ == '__main__':
    main()
