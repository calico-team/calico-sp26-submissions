import sys
input = sys.stdin.readline

def solve():
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))

        dylan_power = P
        cnt = 0

        for e in E:
            dylan_power -= e
            cnt += 1

            if dylan_power < 0:
                print("nah i'd lose")
                break
                
            if cnt % K == 0:
                dylan_power += R
        else:
            print("nah i'd win")

def read_your_input():
    return sys.stdin.read()

if __name__ == "__main__":
    solve()


