def solve():
    T = int(input())
    for _ in range(T):
        N, M = map(int, input().split())
        grid = []
        for i in range(N):
            row = []
            for j in range(M):
                row.append((i + 2 * j) % 5)
            print(' '.join(map(str, row)))

if __name__ == "__main__":
    solve()