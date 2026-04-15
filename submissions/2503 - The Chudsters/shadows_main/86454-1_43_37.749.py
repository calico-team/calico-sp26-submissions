def solve(N: int, S1: list[str], S2: list[str]) -> tuple[int, int]:
    """
    Return the maximal and minimal volume of the shape (in that order)

    N: max dimensions of shape
    S1: projection (shadow) in X-Z plane
    S2: projection (shadow) in Y-Z plane
    """
    # YOUR CODE HERE

    max = 0
    min = 0
    for x in range (len(S1)):
        dot = 0
        dot2 = 0
        tag = 0
        tag2 = 0
        for y in S1[x]:
            if y ==".":
                dot +=1
            if y =="#":
                tag +=1
        for a in S2[x]:
            if a ==".":
                dot2 +=1
            if a == "#":
                tag2 +=1
        max += (N**2)-(N*(dot+dot2))+(dot*dot2)
        if tag >tag2:
            min += tag
        else:
            min += tag2


    return max,min


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        S1 = [input() for _ in range(N)]
        S2 = [input() for _ in range(N)]
        print(*solve(N, S1, S2))


if __name__ == '__main__':
    main()
