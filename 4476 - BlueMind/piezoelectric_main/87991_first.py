import sys
t = int(sys.stdin.readline().strip())

for i in range(t): 
    data = sys.stdin.readline().split()
    if not data:
        break
    
    s = int(data[0])
    d = int(data[1])
    e = int(data[2])
    r = int(data[3])
    

    steps = 2 * (s + d)
    
    
    steps = steps * r
    
    laps = e // steps
    
    print(laps)