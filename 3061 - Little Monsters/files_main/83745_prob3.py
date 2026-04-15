def solve():
    a = input()
    b = input()

    ans = ["#"] * len(a)
    idx = 0



    for i, let in enumerate(a):
        if idx >= len(b):
            break
        if let == b[idx]:
            ans[i] = let
            idx += 1
    return ans

for _ in range(int(input())):
    print(*solve(),sep='')