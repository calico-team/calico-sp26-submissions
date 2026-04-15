'''year = 2026
month = 11
day = 19
T=int(input())
for i in range(T):
    event_name=input().strip()
    Y,M,D = map(int,input().split())
    if Y<year:
        print("we got",event_name,"before gta6")
    elif Y==year and M<month:
        print("we got", event_name, "before gta6")
    elif Y==year and M==month and D<day:
        print("we got", event_name, "before gta6")
    else:
        print("we got gta6 before", event_name)
'''

'''
MOD = 3359232
T = int(input())
while T > 0:
    N=int(input())
    max=N // 3
    if max== 0:
        print(0)
    elif max<= 1000:
        power=1
        current=0
        while current < max:
            power = (power * 2) % MOD
            current += 1
        result = (2 * (power - 1)) % MOD
        print(result)
    else:
        power = pow(2, max, MOD)
        result = (2 * (power - 1)) % MOD
        print(result)
        T-=1
'''
MOD = 10**9 + 7
T = int(input())
cnt = 0
while cnt < T:
    cnt += 1
    L, N = map(int, input().split())
    S = input()
    dep = [0] * L
    d = 0
    i = 0
    while i < L:
        c = S[i]
        if c == '(':
            d += 1
            dep[i] = d
        elif c == ')':
            dep[i] = d
            d -= 1
        else:
            dep[i] = d
        i += 1
    q = [0]
    ans = 0
    while q:
        off = q.pop(0)
        i = 0
        while i < L:
            ad = off + dep[i]
            if ad > N:
                i += 1
                continue
            if S[i] == '|':
                ans += 1
            elif S[i] == 'O':
                q.append(ad)
            i += 1
    print(ans % MOD)