def solve(P, A, B):
    """
    Build a factory with N rows and M columns that produces the target rate.
    
    P: the target numerator of the fraction P / (2^A * 3^B)
    A: the exponent of 2 in the denominator
    B: the exponent of 3 in the denominator
    """


    if P == 0:
        return ["X"]
    if P == 2**A * 3**B:
        return [">"]
    
    steps = [2]*A + [3]*B

    rows = []
    remaining = P
    flowing = 2**A * 3**B

    for i in steps:
        worth = flowing // i
        collectmax = remaining // worth
        remaining -= collectmax * worth
        flowing = worth
    
        if i == 2:
            rows.append((".", ">" if collectmax > 0 else "X"))
        else:
            if collectmax == 0:
                rows.append(("X", "X"))
            elif collectmax == 1:
                rows.append(("X", ">"))
            else:
                rows.append(("<", ">"))
    
    finalrownum = 2*len(rows) + 1
    grid = [["." for _ in range(3)] for _ in range(finalrownum)]
    grid[0][0] = ">"
    grid[0][1] = "v"

    for i, (left, right) in enumerate(rows):
        currow = 2*i + 1
        grid[currow][0] = left
        grid[currow][1] = "S"
        grid[currow][2] = right

        if i < len(rows) - 1:
            grid[currow+1][1] = "v"
        else:
            grid[currow+1][1] = "X"
        
    return [''.join(row) for row in grid]


def main():
    T = int(input())
    for _ in range(T):
        P, A, B = map(int, input().split())
        factory = solve(P, A, B)
        N = len(factory)
        M = len(factory[0])
        print(N, M)
        for row in factory:
            print(row)


if __name__ == '__main__':
    main()
