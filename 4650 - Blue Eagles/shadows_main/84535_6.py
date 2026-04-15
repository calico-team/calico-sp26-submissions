import sys

def solve() -> None:
    data = sys.stdin.read().split()
    it = iter(data)
    t = int(next(it))
    out = []
    for _ in range(t):
        n = int(next(it))
        s1 = [next(it).strip() for _ in range(n)]
        s2 = [next(it).strip() for _ in range(n)]
        max_vol = 0
        min_vol = 0
        for i in range(n):
            a = s1[i].count('#')
            b = s2[i].count('#')
            max_vol += a * b
            min_vol += max(a, b)
        out.append(f'{max_vol} {min_vol}')
    sys.stdout.write('\n'.join(out))

def read_your_input() -> None:
    pass

if __name__ == '__main__':
    solve()
