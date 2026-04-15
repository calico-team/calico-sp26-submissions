import sys
input = sys.stdin.readline
output = sys.stdout.write

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    
    # grid[r][c] = (r + 2*c) % 5
    # For any cross at (r,c): the 5 values are
    # (base-2, base-1, base, base+1, base+2) mod 5
    # where base = (r + 2c) % 5
    # These are 5 consecutive values mod 5 -> always {0,1,2,3,4}
    
    rows = []
    for r in range(n):
        row = [(r + 2 * c) % 5 for c in range(m)]
        rows.append(' '.join(map(str, row)))
    output('\n'.join(rows) + '\n')