def solve(N, A):
    """
    Construct B to minimize total absolute adjacent differences.
    """
    B = [0] * N

    for i in range(N):
        # collect neighbors safely
        candidates = [A[i]]
        if i - 1 >= 0:
            candidates.append(A[i - 1])
        if i + 1 < N:
            candidates.append(A[i + 1])

        # median minimizes absolute deviation locally
        candidates.sort()
        B[i] = candidates[len(candidates) // 2]

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