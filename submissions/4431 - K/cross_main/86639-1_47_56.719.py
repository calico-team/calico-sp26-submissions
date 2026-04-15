import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    T = int(input_data[0])
    pointer = 1
    for _ in range(T):
        N = int(input_data[pointer])
        M = int(input_data[pointer + 1])
        pointer += 2
        grid = []
        for i in range(N):
            row = []
            for j in range(M):
                val = (i + 2 * j) % 5
                row.append(str(val))
            grid.append(" ".join(row))
        print("\n".join(row))
if __name__ == "__main__":
    solve()

            
    
