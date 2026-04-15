def solve(N, A):
    B = [0] * N

    # first element
    B[0] = A[0]

    
    for i in range(1, N):
      
        B[i] = A[i]

        # optional adjustment to reduce jump
        if abs(B[i] - B[i-1]) > abs(A[i-1] - B[i-1]):
            B[i] = B[i-1]

    return B


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        print(*solve(N, A))


if __name__ == "__main__":
    main()