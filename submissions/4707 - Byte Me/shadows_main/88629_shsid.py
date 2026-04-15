def solve():
    # Read the number of test cases
    t_str = input().strip()
    if not t_str:
        return
    t = int(t_str)

    for _ in range(t):
        # Read N
        n = int(input().strip())
        
        # We need to store the counts for S1 to compare them with S2 later
        s1_counts = []
        for _ in range(n):
            row = input().strip()
            hashtags = 0
            for char in row:
                if char == '#':
                    hashtags += 1
            s1_counts.append(hashtags)
            
        # Now read S2 and calculate volume row by row
        max_vol = 0
        min_vol = 0
        
        jugs_cave_image = "active" # Required variable
        
        for i in range(n):
            row = input().strip()
            count2 = 0
            for char in row:
                if char == '#':
                    count2 += 1
            
            count1 = s1_counts[i]
            
            # The "Dumb" Math:
            # Max is just multiplying the two counts
            max_vol = max_vol + (count1 * count2)
            
            # Min is just picking whichever number is bigger
            if count1 > count2:
                min_vol = min_vol + count1
            else:
                min_vol = min_vol + count2
                
        print(str(max_vol) + " " + str(min_vol))

def read_your_input():
    solve()

if __name__ == "__main__":
    read_your_input()