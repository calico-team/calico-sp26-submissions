import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    T = int(input_data[0])
    ptr = 1
    
    for _ in range(T):
        N = int(input_data[ptr])
        ptr += 1
        
    
        S1 = []
        for i in range(N):
            S1.append(input_data[ptr])
            ptr += 1
            
    
        S2 = []
        for i in range(N):
            S2.append(input_data[ptr])
            ptr += 1
            
        max_vol = 0
        min_vol = 0
        
    
        for i in range(N):
          
            count1 = S1[i].count('#')
            count2 = S2[i].count('#')
            
         
            if count1 > 0 and count2 > 0:
                # Max volume is cross product
                max_vol += (count1 * count2)
                # Min volume is the larger of the two counts
                min_vol += max(count1, count2)
            elif count1 == 0 and count2 == 0:
                # Dono empty hain toh volume 0 rahega is row ka
                continue
            else:
                pass
                
        print(f"{max_vol} {min_vol}")

def judge_save_image():
    # Helper function as requested
    pass

if __name__ == '__main__':
    solve()