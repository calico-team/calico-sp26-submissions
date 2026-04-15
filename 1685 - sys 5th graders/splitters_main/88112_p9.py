from fractions import Fraction
import sys

dirs = {'<': (0, -1), '>': (0, 1), '^': (-1, 0), 'v': (1, 0)}

def main():
    input = sys.stdin.read
    data = input().splitlines()
    idx = 0
    T = int(data[idx])
    idx += 1
    for _ in range(T):
        while idx < len(data) and not data[idx].strip():
            idx += 1
        N, M = map(int, data[idx].split())
        idx += 1
        grid = []
        for i in range(N):
            row = data[idx]
            grid.append(row)
            idx += 1

        memo = [[None] * M for _ in range(N)]

        def get_collected(r, c):
            if memo[r][c] is not None:
                return memo[r][c]
            ch = grid[r][c]
            if ch == 'X':
                res = Fraction(0)
            elif ch in dirs:
                dr, dc = dirs[ch]
                nr, nc = r + dr, c + dc
                if not (0 <= nr < N and 0 <= nc < M):
                    res = Fraction(1)
                else:
                    res = get_collected(nr, nc)
            elif ch == 'S':
                valids = []
                deltas = [(-1, 0), (1, 0), (0, -1), (0, 1)]
                for ddr, ddc in deltas:
                    nr, nc = r + ddr, c + ddc
                    if not (0 <= nr < N and 0 <= nc < M):
                        continue
                    nch = grid[nr][nc]
                    if nch == 'X':
                        valids.append((nr, nc))
                    elif nch in dirs:
                        move_dr, move_dc = dirs[nch]
                        if (move_dr, move_dc) == (-ddr, -ddc):
                            continue
                        valids.append((nr, nc))
                k = len(valids)
                res = Fraction(0)
                for nr, nc in valids:
                    res += get_collected(nr, nc) / k
            else:
                res = Fraction(0)
            memo[r][c] = res
            return res

        frac = get_collected(0, 0)
        p = frac.numerator
        q = frac.denominator
        print(p, q)

if __name__ == "__main__":
    main() 