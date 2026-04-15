import sys

def solve():
    input_data = sys.stdin.read().strip().split()
    if not input_data:
        return
    t = int(input_data[0])
    idx = 1
    out_lines = []
    for _ in range(t):
        n = int(input_data[idx])
        idx += 1
        A = list(map(int, input_data[idx:idx+n]))
        idx += n
        b = A[:]
        out_lines.append(' '.join(map(str, b)))
    sys.stdout.write('\n'.join(out_lines))

if __name__ == "__main__":
    solve()