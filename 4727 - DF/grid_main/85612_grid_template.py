def solve(N, A):
    B = [0] * N
    if N <= 3:
        median = sorted(A)[N // 2]
        for i in range(N):
            B[i] = median
    else:
        for i in range(N):
            B[i] = A[i]
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
