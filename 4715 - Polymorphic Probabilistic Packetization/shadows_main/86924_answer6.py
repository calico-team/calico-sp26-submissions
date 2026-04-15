import sys

def solve():
    line = sys.stdin.readline()
    if not line:
        return
    T = int(line.strip())
    
    for _ in range(T):
        N = int(sys.stdin.readline().strip())
        s1 = []
        for _ in range(N):
            s1.append(sys.stdin.readline().strip())
            
        s2 = []
        for _ in range(N):
            s2.append(sys.stdin.readline().strip())

        max_v = 0
        min_v = 0
        
        for i in range(N):
            count1 = s1[i].count('#')
            count2 = s2[i].count('#')
            max_v = max_v + (count1 * count2)

            if count1 > count2:
                min_v = min_v + count1
            else:
                min_v = min_v + count2

        print(max_v, min_v)

solve()