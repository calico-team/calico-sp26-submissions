import sys
import math
from collections import defaultdict

def main():
    input = sys.stdin.read().split()
    ptr = 0
    T = int(input[ptr])
    ptr += 1
    for _ in range(T):
        K = int(input[ptr])
        N = int(input[ptr+1])
        M = int(input[ptr+2])
        P = int(input[ptr+3])
        Q = int(input[ptr+4])
        ptr += 5

        astro_map = defaultdict(list)
        asteroids = []
        for idx in range(K):
            x = int(input[ptr])
            y = int(input[ptr+1])
            ptr += 2
            asteroids.append( (x,y) )
            astro_map[ (x,y) ].append(idx)

        x0, y0 = asteroids[0]
        curr_x, curr_y = x0, y0

        lcm = N * M // math.gcd(N, M)
        step = 0

        visited = set()
        visited.add( (curr_x, curr_y) )

        ans = -1
        while step < lcm:
            curr_x = (curr_x + Q ) % N
            curr_y = (curr_y + P ) % M
            step +=1

            if (curr_x, curr_y) in astro_map:
                ans = astro_map[ (curr_x, curr_y) ][0]
                break

            if (curr_x, curr_y) in visited:
                break
            visited.add( (curr_x, curr_y) )

        print(ans)

if __name__ == "__main__":
    main()
            
                      
