import sys

def main():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    T = int(input_data[0])
    idx = 1
    
    for _ in range(T):
        L = int(input_data[idx])
        W = int(input_data[idx+1])
        E = int(input_data[idx+2])
        R = int(input_data[idx+3])
        idx += 4
        
        triangle_area = 2 * (L + W)
        electricity_per_lap = triangle_area * R
        
        laps = E // electricity_per_lap
        print(laps)

if __name__ == '__main__':
    main()

def read_your_input():
    pass