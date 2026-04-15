import sys

def main():
    data = sys.stdin.read().split()
    idx =0
    
    T= int(data[idx]); idx += 1
    
    for _ in range(T):
        n = int(data[idx]); idx += 1
        
        S_1 = []
        for i in range(n):
            S_1.append(data[idx]); idx += 1
        
        S_2 = []
        for i in range(n):
            S_2.append(data[idx]); idx += 1
        
        jugs_cave_image = None
        
        max_volume = 0
        min_volume = 0
        
        for y in range(n):
            c1 = S_1[y].count('#')
            c2 = S_2[y].count('#')
            max_volume += c1 * c2
            min_volume += max(c1, c2)
        
        print(max_volume, min_volume)

def read_input():
    main()

read_input()