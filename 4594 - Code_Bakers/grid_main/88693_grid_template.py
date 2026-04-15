def solve(N, A):
    B = [0] * N

    B[0] = A[0]

    for i in range(1, N):
        # option 1: keep same as A[i]
        opt1 = A[i]

        # option 2: smooth with previous B
        opt2 = B[i - 1]

        # choose better local cost
        cost1 = abs(A[i] - opt1) + abs(opt1 - B[i - 1])
        cost2 = abs(A[i] - opt2) + abs(opt2 - B[i - 1])

        B[i] = opt1 if cost1 <= cost2 else opt2

    return B


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        print(*solve(N, A))


if __name__ == "__main__":
    main()