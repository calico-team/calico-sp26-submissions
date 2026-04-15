def solve(N: int, S1: list[str], S2: list[str]) -> tuple[int, int]:
    """
    Return the maximal and minimal volume of the shape (in that order)
    
    N: max dimensions of shape
    S1: projection (shadow) in X-Z plane
    S2: projection (shadow) in Y-Z plane
    """

    min = 0
    max = 0
    for i in range(N):
        solved = solveLn(S1[i],S2[i])
        min += solved[0]
        max += solved[1]

    # YOUR CODE HERE
    return max, min

def solveLn(ln1,ln2):
    count1 = 0
    count2 = 0
    for i in range(len(ln1)):
        if ln1[i] == '#':
            count1 += 1
        if ln2[i] == '#':
            count2 += 1
    
    return [max(count1,count2),count1 * count2]


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        S1 = [input() for _ in range(N)]
        S2 = [input() for _ in range(N)]
        print(*solve(N, S1, S2))


if __name__ == '__main__':
    main()
