import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    T = int(input_data[0])
    idx = 1
    out = []
    for _ in range(T):
        L = int(input_data[idx])
        W = int(input_data[idx+1])
        E = int(input_data[idx+2])
        R = int(input_data[idx+3])
        idx += 4
        
        triangle_area = 2 * (L + W)
        laps = E // (triangle_area * R)
        out.append(str(laps))
    sys.stdout.write("\n".join(out))

def read_your_input():
    pass

if __name__ == '__main__':
    solve()
    read_your_input()