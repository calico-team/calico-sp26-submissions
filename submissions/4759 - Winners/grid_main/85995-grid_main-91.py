def solve(N, A):
    L = [0] * N
    R = [0] * N
    L[0] = A[0]
    R[0] = A[0]
    for i in range(1, N):
        x = A[i]
        if x < L[i - 1]:
            L[i] = x
            R[i] = L[i - 1]
        elif x > R[i - 1]:
            L[i] = R[i - 1]
            R[i] = x
        else:
            L[i] = L[i - 1]
            R[i] = x
    B = [0] * N
    B[-1] = L[-1]
    for i in range(N - 2, -1, -1):
        if B[i + 1] < L[i]:
            B[i] = L[i]
        elif B[i + 1] > R[i]:
            B[i] = R[i]
        else:
            B[i] = L[i]
    return B


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        print(" ".join(str(x) for x in result))


if __name__ == "__main__":
    main()
