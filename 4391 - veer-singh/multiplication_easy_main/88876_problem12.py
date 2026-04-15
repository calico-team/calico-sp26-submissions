import math

def solve(N, M, D, cells):
    """
    Return a tuple (A, discards) where:
      A: list of N integers in [1, 10^9]
      discards: list of at most D distinct 1-indexed cell indices to discard

    The discards output line will begin with t, the number of discarded
    cells, followed by those t indices; t is computed and written for
    you in main().

    N: length of the array A
    M: number of cells
    D: maximum number of cells you may discard
    cells: list of M tuples (R, C, V, W); for cell k (1-indexed), the product
           A[R] * A[C] should be close to the target V, with weight W
    """

    rowColMap = [[] for _ in range(N + 1)]
    for idx, (rowIdx, colIdx, val, weight) in enumerate(cells):
        rowColMap[rowIdx].append((colIdx, val, weight, idx + 1))
        rowColMap[colIdx].append((rowIdx, val, weight, idx + 1))

    sumVal = sum(cell[2] for cell in cells)
    avgVal = sumVal/M
    initVal = int(math.sqrt(avgVal))

    if initVal < 1:
        initVal = 1
    
    ansA = [initVal]*(N + 1)

    for _ in range(3):
        for i in range(1, N + 1):
            numSum = 0
            denSum = 0
            for partIdx, targetV, w, _ in rowColMap[i]:
                numSum += w * (targetV / ansA[partIdx])
                denSum += w
            if denSum > 0:
                ansA[i] = max(1, min(10**9, int(numSum / denSum)))

    penaltyList = []
    for idx, (r, c, v, w) in enumerate(cells):
        relErr = abs(ansA[r] * ansA[c] - v) / v
        penaltyList.append((w * relErr, idx + 1))
    
    penaltyList.sort(key=lambda x: x[0], reverse=True)
    discardIdxs = [penaltyList[i][1] for i in range(min(D, M))]

    return ansA[1:], discardIdxs


def main():
    N, M, D = map(int, input().split())
    cells = []
    for _ in range(M):
        R, C, V, W = map(int, input().split())
        cells.append((R, C, V, W))
    A, discards = solve(N, M, D, cells)
    print(' '.join(str(x) for x in A))
    print(' '.join(str(x) for x in [len(discards)] + list(discards)))


if __name__ == '__main__':
    main()