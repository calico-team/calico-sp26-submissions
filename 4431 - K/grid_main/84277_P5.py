import sys
def solve():
    line1 = sys.stdin.readline()
    if not line1:
        return
    t = int(line1.strip())
    for _ in range(t):
        n_line = sys.stdin.readline()
        if not n_line:
            break
        n = int(n_line.strip())
        a_line = sys.stdin.readline()
        if not a_line:
            break
        a = list(map(int, a_line.split()))
        print(*(a))
if __name__ == "__main__":
    solve()
        
            
    
