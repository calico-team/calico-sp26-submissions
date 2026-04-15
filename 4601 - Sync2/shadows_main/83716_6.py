import sys

def main():
    data = sys.stdin.read().split()
    idx = 0
    
    t = int(data[idx]); idx += 1
    
    for _ in range(t):
        n = int(data[idx]); idx += 1
        
        s1 = []
        for i in range(n):
            s1.append(data[idx]); idx += 1
        
        s2 = []
        for i in range(n):
            s2.append(data[idx]); idx += 1
        
        ans_max = 0
        ans_min = 0
        
        for z in range(n):
            cx = s1[z].count('#')
            cy = s2[z].count('#')
            ans_max += cx * cy
            if cx > 0 and cy > 0:
                ans_min += max(cx, cy)
        
        print(ans_max, ans_min)

main()

def read_your_input():
    data = sys.stdin.read().split()
    return data