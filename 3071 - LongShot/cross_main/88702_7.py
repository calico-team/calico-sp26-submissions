pattern = [
    [0, 1, 2, 3, 4],
    [1, 2, 3, 4, 0],
    [2, 3, 4, 0, 1],
    [3, 4, 0, 1, 2],
    [4, 0, 1, 2, 3]
]

T = int(input())
b = []
for l in range(T):
    N, M = map(int, input().split())
    for i in range(N):
        a = [str(pattern[i % 5][m % 5]) for m in range(M)]
        b.append(" ".join(a))
print("\n".join(b))