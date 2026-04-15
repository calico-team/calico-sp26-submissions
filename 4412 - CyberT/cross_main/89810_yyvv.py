import sys

def make_the_criss_cross(n, m):
    out = []
    for r in range(n):
        row = [(2*r + c) % 5 for c in range(m)]
        out.append(' '.join(map(str, row)))
    return '\n'.join(out)

def main():
    lines = sys.stdin.read().splitlines()
    idx = 0
    t = int(lines[idx]); idx += 1
    out = []
    for _ in range(t):
        n, m = map(int, lines[idx].split()); idx += 1
        out.append(make_the_criss_cross(n, m))
    sys.stdout.write('\n'.join(out) + '\n')

main()

def read_your_input():
    lines = sys.stdin.read().splitlines()
    idx = 0
    t = int(lines[idx]); idx += 1
    cases = []
    for _ in range(t):
        n, m = map(int, lines[idx].split()); idx += 1
        cases.append((n, m))
    return cases