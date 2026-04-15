import sys
input = sys.stdin.readline

def solve():
    t = int(input())
    for _ in range(t):
        n, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        
        dylan_power = P
        uses = 0
        ok = True
        
        for i in range(n):
            if dylan_power < E[i]:
                while uses > 0 and dylan_power < E[i]:
                    dylan_power += R
                    uses -= 1
                if dylan_power < E[i]:
                    ok = False
                    break
            
            dylan_power -= E[i]
            
            if (i + 1) % K == 0:
                uses += 1
        
        print("nah i'd win" if ok else "nah i'd lose")

def read_your_input():
    solve()

if __name__ == "__main__":
    read_your_input()