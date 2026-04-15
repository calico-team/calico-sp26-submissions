def solve(N, S1, S2):
    max_volume = 0
    min_volume = 0
    
    for z in range(N):
        x_count = 0
        y_count = 0
        
        for x in range(N):
            if S1[z][x] == '#':
                x_count += 1
        
        for y in range(N):
            if S2[z][y] == '#':
                y_count += 1
        
        # maximum volume contribution
        max_volume += x_count * y_count
        
        # minimum volume contribution
        min_volume += max(x_count, y_count)
    
    return max_volume, min_volume

def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        S1 = [input() for _ in range(N)]
        S2 = [input() for _ in range(N)]
        print(*solve(N, S1, S2))


if __name__ == '__main__':
    main()
