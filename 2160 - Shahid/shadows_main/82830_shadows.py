import sys

def solve():
    data = sys.stdin.read().split('\n')
    idx = 0
    T = int(data[idx]); idx += 1

    for _ in range(T):
        N = int(data[idx]); idx += 1

        s1 = []
        for i in range(N):
            s1.append(data[idx]); idx += 1
        s2 = []
        for i in range(N):
            s2.append(data[idx]); idx += 1

        jugs_cave_image = 0
        max_vol = 0
        min_vol = 0

        for z in range(N):
            a = s1[z].count('#')
            b = s2[z].count('#')
            max_vol += a * b
            min_vol += max(a, b)

        print(max_vol, min_vol)

def read_your_input():
    return sys.stdin.read()

if __name__ == "__main__":
    solve()
