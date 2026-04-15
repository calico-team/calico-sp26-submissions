pattern = [
    [0, 1, 2, 3, 4],
    [1, 2, 3, 4, 0],
    [2, 3, 4, 0, 1],
    [3, 4, 0, 1, 2],
    [4, 0, 1, 2, 3]
]

T = int(input())
a = []
for q in range(T):
    N, M = map(int, input().split())
    for i in range(N):
        b = [str(pattern[i % 5][j % 5]) for j in range(M)]
        a.append(" ".join(b))
    if q != T - 1:
        a.append("")
print("\n".join(a))



