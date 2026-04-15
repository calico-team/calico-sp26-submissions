def solve():
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        curs = list(map(int, input().split()))
        a_live = True
        for i in range(N):
            P -= curs[i]
            if P < 0:
                a_live = False
                break
            if (i + 1) % K == 0:
                P += R
        if a_live:
            print("nah i'd win")
        else:
            print("nah i'd lose")

if __name__ == "__main__":
    solve()