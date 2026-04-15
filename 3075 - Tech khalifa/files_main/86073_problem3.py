import sys
data = sys.stdin.read().strip().split("\n")
idxx = 0
T = int(data[idxx]); idxx += 1

for _ in range(T):
    Ss = data[idxx].strip(); idxx += 1
    Aa = data[idxx].strip(); idxx += 1
    
    r = []
    g = 0
    v = len(Aa)
    u = len(Ss)
    
    for j in range(len(Ss)):
        if g < v and Ss[j] == Aa[g]:
            r.append(Ss[j])
            g += 1
        else:
            r.append('-')
    
    print("".join(r))