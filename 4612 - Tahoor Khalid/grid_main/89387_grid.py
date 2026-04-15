def solve(N, A):
    A_sorted = sorted(A)
    
    median = A_sorted[N // 2]
    
    # make B constant
    return [median] * N


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        print(' '.join(str(x) for x in result))


if __name__ == '__main__':
    main()