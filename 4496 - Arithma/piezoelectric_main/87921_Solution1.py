import sys

def solve():
    
    line = sys.stdin.readline()
    if not line:
        return
    t = int(line.strip())
    
    for _ in range(t):
        
        data = sys.stdin.readline().split()
        if not data:
            break
            
        s = int(data[0])
        d = int(data[1])
        e = int(data[2])
        r = int(data[3])
        
    
        steps_per_lap = 2 * (s + d)
        
        
        elec_per_lap = steps_per_lap * r
        
        
        
        laps = e // elec_per_lap
        
        print(laps)

if __name__ == "__main__":
    solve()