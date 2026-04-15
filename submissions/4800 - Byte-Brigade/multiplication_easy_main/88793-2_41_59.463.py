import math
from collections import defaultdict
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

    log_vals = [0.0] *(N+1) 
    log_sum= defaultdict(float)
    weight_sum = defaultdict(float)

    for r, c, v, w in cells:
        log_v = math.log(v)
        log_sum[r] += w* log_v
        weight_sum[r] +=w
        log_sum[c] += w*log_v
        weight_sum[c] +=w

    for i in range(1,N+1):
        if weight_sum[i]>0:
            log_vals[i] =log_sum[i] /weight_sum[i]/2.0
        else:
            log_vals[i]=0.0

    result=[]
    for i in range(1,N+1):
        val = int(round(math.exp(log_vals[i])))
        val = max(1,min(10**9,val))
        result.append(val)

    penalties=[]
    for idx,(r,c,v,w) in enumerate(cells):
        product =result[r- 1] *result[c - 1]
        penalty =w*abs(product -v) / v
        penalties.append((penalty,idx+ 1))  # 1-indexed

    penalties.sort(reverse=True)
    discards = [idx for _, idx in penalties[:D]]


    return result, discards

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
