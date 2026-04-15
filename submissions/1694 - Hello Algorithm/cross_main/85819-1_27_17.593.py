import sys
    
t_num = int(input())

tile_block = [
    [0, 1, 2, 3, 4],
    [2, 3, 4, 0, 1],
    [4, 0, 1, 2, 3],
    [1, 2, 3, 4, 0],
    [3, 4, 0, 1, 2]
]

res = []

for _ in range(t_num):
    row_limit, col_limit = map(int, input().split())
    
    for r_idx in range(row_limit):
        mapped_row = [str(tile_block[r_idx % 5][c_idx % 5]) for c_idx in range(col_limit)]
        res.append(" ".join(mapped_row))
        
sys.stdout.write('\n'.join(res) + '\n')