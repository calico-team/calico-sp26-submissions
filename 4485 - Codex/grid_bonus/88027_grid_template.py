def solve(N, A):
    return A   


def main():
    t = int(input())
    for _ in range(t):
        N = int(input())
        A = list(map(int, input().split()))
        
        res = solve(N, A)
        print(*res)


if __name__ == "__main__":
    main()