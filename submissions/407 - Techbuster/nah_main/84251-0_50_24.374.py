import sys
input = sys.stdin.readline

def solve():
    l, P, x, K =map(int, input().split())
    E= list(map(int, input().split()))
    
    dylan_power = P
    curses_defeated = 0
    
    for e in E:
        dylan_power -= e
        if dylan_power <0:
            print("nah i'd lose")
            return
        curses_defeated+= 1
        if curses_defeated % K ==0:
            dylan_power += x
    
    print("nah i'd win")

T = int(input())
for _ in range(T):
    solve()

def read_input():
    return sys.stdin.readline().strip()