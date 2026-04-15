def solve(N, A):
    def med(a, b, c):
        return sorted([a, b, c])[1]

    B = []
    for i in range(N):
        left  = A[i - 1] if i > 0 else A[i]
        right = A[i + 1] if i < N - 1 else A[i]
        B.append(med(left, A[i], right))
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
