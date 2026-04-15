def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    if not data:
        return
    T = int(data[0])
    out = []
    idx = 1
    
    for _ in range(T):
        P = int(data[idx])
        A = int(data[idx+1])
        B = int(data[idx+2])
        idx += 3

        D = (2**A) * (3**B)

        # Edge cases for 100% and 0% collection
        if P == D:
            out.append("1 1\n^")
            continue
        if P == 0:
            out.append("1 1\nX")
            continue

        divisors = [3] * B + [2] * A
        k = len(divisors)

        rows = 3
        cols = 2 * k + 1
        grid = [["." for _ in range(cols)] for _ in range(rows)]

        # Input stream routing to the main bus
        grid[0][0] = "v"
        grid[1][0] = ">"

        num = P
        den = D

        for i in range(1, k + 1):
            d = divisors[i-1]
            c = (num * d) // den
            num = (num * d) % den

            col = 2 * i - 1
            grid[1][col] = "S"

            # Continue bus or cap the end with a destroy tile
            if i < k:
                grid[1][col+1] = ">"
            else:
                grid[1][col+1] = "X"

            # Configure top and bottom outputs based on required collection count
            if d == 2:
                grid[0][col] = "^" if c == 1 else "X"
                grid[2][col] = "."
            elif d == 3:
                if c == 2:
                    grid[0][col] = "^"
                    grid[2][col] = "v"
                elif c == 1:
                    grid[0][col] = "^"
                    grid[2][col] = "X"
                else:
                    grid[0][col] = "X"
                    grid[2][col] = "X"

        out.append(f"{rows} {cols}")
        for row in grid:
            out.append("".join(row))

    print("\n".join(out))

if __name__ == '__main__':
    solve()