import sys
input = sys.stdin.readline

def solve(N, P, R, K, E):
    defeated = 0
    alive = True

    for i in range(N):
        P = P - E[i]

        if P < 0:
            alive = False
            break

        defeated += 1

        if defeated % K == 0:
            P += R

    if alive:
        return "nah i'd win"
    else:
        return "nah i'd lose"

def main():
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))

main()