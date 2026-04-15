jugs_cave_image = True

def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        S1 = [input().strip() for _ in range(N)]
        S2 = [input().strip() for _ in range(N)]
        
        max_vol = 0
        min_vol = 0
        
        for z in range(N):
            a = S1[z].count('#')  # '#' count in row z of S1
            b = S2[z].count('#')  # '#' count in row z of S2
            # Max: place block at every valid (x,y,z) = a*b blocks
            max_vol += a * b
            # Min: minimum edge cover of complete bipartite graph K_{a,b}
            # = max(a, b)
            min_vol += max(a, b)
        
        print(max_vol, min_vol)

if __name__ == '__main__':
    main()