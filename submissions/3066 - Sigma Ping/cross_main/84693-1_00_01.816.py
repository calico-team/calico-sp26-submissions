def create_grid(n, m):
    return [[(r + 2 * c) % 5 for c in range(m)] for r in range(n)]

def solve(test_cases):
    for n, m in test_cases:
        grid = create_grid(n, m)
        for row in grid:
            print(*row)

T = int(input())
test_cases = []
for _ in range(T):
    n, m = map(int, input().split())
    test_cases.append((n, m))
solve(test_cases)
