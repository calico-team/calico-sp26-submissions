import sys

def solve():
    all_data = sys.stdin.read().split()
    if len(all_data) == 0:
        return
    pos = 0
    T = int(all_data[pos])
    pos += 1
    for _ in range(T):
        n = int(all_data[pos])
        pos += 1
        s1 = []
        for i in range(n):
            s1.append(all_data[pos])
            pos += 1
        s2 = []
        for i in range(n):
            s2.append(all_data[pos])
            pos += 1
        
        maxv = 0
        minv = 0
        for i in range(n):
            r1 = s1[i]
            r2 = s2[i]
            c1 = 0
            c2 = 0
            for ch in r1:
                if ch == '#':
                    c1 += 1
            for ch in r2:
                if ch == '#':
                    c2 += 1
            if c1 == 0 or c2 == 0:
                continue
            maxv = maxv + c1 * c2
            if c1 > c2:
                minv = minv + c1
            else:
                minv = minv + c2
        print(maxv, minv)

if __name__ == "__main__":
    solve()
