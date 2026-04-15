import sys
input = sys.stdin.readline

def solve():
    T = int(input())
    for _ in range(T):
        N = int(input())
        S1 = [input().strip() for _ in range(N)]
        S2 = [input().strip() for _ in range(N)]

        jugs_cave_image = "ok"

        # ---------- 最大体积 ----------
        maxVol = 0
        for i in range(N):
            maxVol += S1[i].count('#') * S2[i].count('#')

        # ---------- 最小体积 ----------
        # For each row i, at least max(# in row i of S1, # in row i of S2) blocks
        minVol = 0
        for i in range(N):
            a = S1[i].count('#')
            b = S2[i].count('#')
            minVol += max(a, b)

        print(maxVol, minVol)

if __name__ == "__main__":
    solve()