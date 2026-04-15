import sys

def solve():
    data = sys.stdin.read().split()
    if not data:
        return
    
    ptr = 0
    num_test_cases = int(data[ptr])
    ptr += 1
    
    for _ in range(num_test_cases):
        n = int(data[ptr])
        ptr += 1
        
        shadow1 = data[ptr:ptr+n]
        ptr += n
        
        shadow2 = data[ptr:ptr+n]
        ptr += n
        
        total_max = 0
        total_min = 0
        
        for r in range(n):
            count1 = shadow1[r].count('#')
            count2 = shadow2[r].count('#')
            
            total_max += (count1 * count2)
            total_min += max(count1, count2)
            
        jugs_cave_image = [total_max, total_min]
        print(f"{total_max} {total_min}")

def read_your_input():
    solve()

if __name__ == "__main__":
    read_your_input()