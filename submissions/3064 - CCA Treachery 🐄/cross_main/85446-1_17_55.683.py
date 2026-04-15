from collections import deque

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())

    rotation1 = [i % 5 for i in range(m)]


    

    
   # if m == 4:



    print(*rotation1)

    for _ in range(n - 1):
        next_line = [0 for _ in range(m)]
        
        for i in range(m - 2):
            next_line[i + 2] = rotation1[i]
        
        next_line[0] = (rotation1[0] - 2) % 5
        next_line[1] = (rotation1[1] - 2) % 5
        
        
        print(*next_line)

        rotation1 = next_line

        