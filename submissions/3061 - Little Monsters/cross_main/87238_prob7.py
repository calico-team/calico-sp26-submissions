def solve():
    ans = []
    length, width = map(int, input().split())
    for i in range(length):
        phaseshift = i % 5
        cur = []
        for j in range(width):
            cur.append((phaseshift + j * 2) % 5)
        ans.append(cur)
    return ans

for _ in range(int(input())):
    yay = solve()
    for row in yay:
        print(*row)

    