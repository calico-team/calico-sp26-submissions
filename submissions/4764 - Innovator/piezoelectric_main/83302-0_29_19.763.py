def solve():
    
    import sys
    input_data = sys.stdin.read().split()
    
    if not input_data:
        return

    t = int(input_data[0])
    current = 1
    
    for _ in range(t):
        
        length = int(input_data[current])
        width = int(input_data[current + 1])
        energy_needed = int(input_data[current + 2])
        rate = int(input_data[current + 3])
        current += 4
        
        triangle_area = 2 * (length + width)
        
        energy_per_lap = triangle_area * rate
        
        total_laps = energy_needed // energy_per_lap
        
        print(total_laps)

def read_your_input():
    solve()

if __name__ == "__main__":
    read_your_input()