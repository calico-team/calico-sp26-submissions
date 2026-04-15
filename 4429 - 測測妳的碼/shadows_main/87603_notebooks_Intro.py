import sys

def solve():
    data = sys.stdin.read().splitlines()
    data = [line.replace(" ", "").strip() for line in data if line.strip()]
    
    if not data:
        return
        
    pos = 0
    T = int(data[pos])
    pos += 1
    
    for _ in range(T):
        n = int(data[pos])
        pos += 1
        s1 = data[pos : pos+n]
        pos += n
        
        s2 = data[pos : pos+n]
        pos += n
        
        maxv = 0
        minv = 0
        for i in range(n):
            c1 = s1[i].count('#')
            c2 = s2[i].count('#')
            
            maxv += c1 * c2
            minv += max(c1, c2) 
            
        print(f"{maxv} {minv}")

if __name__ == "__main__":
    solve()
