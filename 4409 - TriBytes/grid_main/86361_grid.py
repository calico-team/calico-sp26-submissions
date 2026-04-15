import heapq

def solve(N, A):
    if N == 0:
        return []

    lo = [0] * N
    hi = [0] * N

    # upper = max-heap of lower bounds (negate for Python's min-heap)
    # lower = min-heap of upper bounds
    upper = []   # stores -value (max-heap via negation)
    lower = []   # stores +value (min-heap)

    for i in range(N):
        ai = A[i]

        heapq.heappush(upper, -ai)   # lower bound side: push A[i]
        heapq.heappush(lower,  ai)   # upper bound side: push A[i]
        cur_lo = -upper[0]
        cur_hi =  lower[0]

        if cur_lo > cur_hi:
            # Clip: bring them together by removing the outlier from each heap
            # and re-inserting the other's top
            bad_lo = -heapq.heappop(upper)   # too-large lower bound
            bad_hi =  heapq.heappop(lower)   # too-small upper bound
            heapq.heappush(upper, -bad_hi)   # clamp lower bound down to hi
            heapq.heappush(lower,  bad_lo)   # clamp upper bound up  to lo

        lo[i] = -upper[0]
        hi[i] =  lower[0]

    # Back-substitution: choose b[i] in [lo[i], hi[i]], propagating right→left
    b = [0] * N
    b[N - 1] = lo[N - 1]   # any value in interval works; pick lo for stability

    for i in range(N - 2, -1, -1):
        # Clip previous b[i+1] into this interval — propagates smoothness
        b[i] = max(lo[i], min(hi[i], b[i + 1]))

    return b


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        print(' '.join(str(x) for x in result))


if __name__ == '__main__':
    main()