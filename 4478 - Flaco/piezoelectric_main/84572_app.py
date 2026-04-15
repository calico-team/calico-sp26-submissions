import sys

def s():
    a = sys.stdin.read().split()
    if not a:
        return
    
    b = int(a[0])
    c = 1
    
    for _ in range(b):
        x = int(a[c])
        y = int(a[c+1])
        z = int(a[c+2])
        k = int(a[c+3])
        c += 4
        
        m = 2 * (x + y)
        v = m * k
        f = z // v
        
        print(f)

if __name__ == "__main__":
    s()