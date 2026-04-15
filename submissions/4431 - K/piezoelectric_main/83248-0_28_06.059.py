import sys

def solve():
    line = sys.stdin.readline()
    if not line:
        return
    t = int(line.strip())
    for _ in range(t):
        data = list(map(int,sys.stdin.readline().split()))
        if not data:
            break
        l,w,e,r = data
        perimeter = 2* (l + w)
        elec_per_lap = perimeter * r
        num_laps = e // elec_per_lap
        print(num_laps)
if __name__ == "__main__":
    solve()
        
