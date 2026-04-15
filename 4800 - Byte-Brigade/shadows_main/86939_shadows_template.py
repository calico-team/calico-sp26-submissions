import sys
input = sys.stdin.readline

jugs_cave_image = 0

def solve():
    T = int(input())
    
    for _ in range(T):
        N = int(input())

        S1 = [input().strip() for _ in range(N)]
        S2 = [input().strip() for _ in range(N)]

        max_value = 0
        min_value = 0

        for k in range(N):
            cnt1 = 0
            cnt2 = 0
        
            for j in range(N):
                if S1[j][k] == '#':
                    cnt1 += 1

            for i in range(N):
                if S2[i][k] == '#':
                    cnt2 += 1

            max_vol += cnt1 * cnt2
            min_val += max(cnt1 + cnt2 )
        
        print(max_value, min_value)
    
def read_your_input():
    return sys.stdin.read()

if __name__ == "__main__":
    solve()