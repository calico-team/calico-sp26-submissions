def solve(N, A):
    
    print("new element of code is running now")
    if N == 1:
        return [A[0]]
    if N == 2:
        return [A[0], A[0]]

    median = sorted(A)[1]
    return [median, median, median]


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        print(' '.join(str(x) for x in result))


if __name__ == '__main__':
    main()