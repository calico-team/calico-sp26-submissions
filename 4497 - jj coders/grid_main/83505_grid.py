import heapq

def solve(N, A):
    L = []  # max-heap (negated)
    R = []  # min-heap
    min_val = 0
    flat_ranges = []

    a = A[0]
    heapq.heappush(L, -a)
    heapq.heappush(R, a)
    flat_ranges.append((-L[0], R[0]))

    for i in range(1, N):
        # Infimal convolution: slopes clip to ±1, keep only extremes
        l_max = -L[0]
        r_min = R[0]
        L = [-l_max]
        R = [r_min]

        a = A[i]

        # Push a to L, fix invariant
        heapq.heappush(L, -a)
        if -L[0] > R[0]:
            l = -heapq.heappop(L)
            r = heapq.heappop(R)
            min_val += l - r
            heapq.heappush(L, -r)
            heapq.heappush(R, l)

        # Push a to R, fix invariant
        heapq.heappush(R, a)
        if -L[0] > R[0]:
            l = -heapq.heappop(L)
            r = heapq.heappop(R)
            min_val += l - r
            heapq.heappush(L, -r)
            heapq.heappush(R, l)

        flat_ranges.append((-L[0], R[0]))

    # Backward reconstruction: B[i] = clamp(B[i+1], l_i, r_i)
    B = [0] * N
    B[N-1] = flat_ranges[N-1][0]
    for i in range(N-2, -1, -1):
        l, r = flat_ranges[i]
        B[i] = max(l, min(r, B[i+1]))

    return B

def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        print(' '.join(str(x) for x in result))

if __name__ == '__main__':
    main()