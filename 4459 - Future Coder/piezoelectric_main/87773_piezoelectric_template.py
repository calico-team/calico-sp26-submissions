import sys

def solve():
    data = list(map(int, sys.stdin.read().split()))
    t = data[0]
    idx = 1
    results = []
    
    for _ in range(t):
        l, w, e, r = data[idx:idx + 4]
        idx += 4
        
        perimeter = 2 * (l + w)
        total_cost = perimeter * r
       
        if total_cost == 0:
            results.append("0")
        else:
            results.append(str(e // total_cost))
   
    sys.stdout.write("\n".join(results) + "\n")

if __name__ == "__main__":
    solve()