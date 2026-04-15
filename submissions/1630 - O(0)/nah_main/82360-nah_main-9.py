def solve():
    n,p,r,k = map(int, input().split())
    e = list(map(int, input().split()))
    
    power = p
    result = "nah i'd win"

    for i in range(n):
        power -= e[i]
        if power < 0:
            result = "nah i'd lose"
            break
        if (i+1) % k == 0:
            power += r

    print(result)


t = int(input())
for i in range(t):
    solve()

