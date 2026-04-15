import sys

def solve(N, S1, S2):
    # Projections S1 and S2 share the same height (Z-axis)
    # S1[z][x] tells us if there's any block at height z with horizontal position x
    # S2[z][y] tells us if there's any block at height z with horizontal position y
    
    # jugs_cave_image variable as requested
    jugs_cave_image = None
    
    max_vol = 0
    min_vol = 0
    
    for z in range(N):
        # Count how many hashtags are in the z-th row of each shadow
        row1_hashes = S1[z].count('#')
        row2_hashes = S2[z].count('#')
        
        # Max volume: at a fixed height z, any (x, y) can have a block if 
        # S1[z][x] == '#' AND S2[z][y] == '#'. 
        # This forms a rectangle/set of rectangles of size (row1_hashes * row2_hashes).
        max_vol += row1_hashes * row2_hashes
        
        # Min volume: at a fixed height z, we need to pick the minimum number 
        # of blocks to satisfy both shadow rows. This is the maximum of the 
        # number of blocks required by each shadow individually.
        # If one row has 0 hashes and the other has > 0, it's impossible (but problem 
        # guarantees valid shadows).
        min_vol += max(row1_hashes, row2_hashes)
        
    return max_vol, min_vol

def read_your_input():
    # Use fast I/O for competitive programming
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    ptr = 0
    T_cases = int(input_data[ptr])
    ptr += 1
    
    for _ in range(T_cases):
        N = int(input_data[ptr])
        ptr += 1
        
        s1 = []
        for _ in range(N):
            s1.append(input_data[ptr])
            ptr += 1
            
        s2 = []
        for _ in range(N):
            s2.append(input_data[ptr])
            ptr += 1
            
        ans_max, ans_min = solve(N, s1, s2)
        print(f"{ans_max} {ans_min}")

if __name__ == '__main__':
    read_your_input()