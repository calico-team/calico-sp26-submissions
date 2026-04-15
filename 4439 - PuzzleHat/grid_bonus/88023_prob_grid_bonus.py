def the_two_tower_heights(A):
    n = len(A)
    plateaus = []
    l, r = A[0], A[0]
    plateaus.append((l, r))

    for i in range(1, n):
        a = A[i]
        if a < l:
            l, r = a, l
        elif a > r:
            l, r = r, a
        else:
            l, r = a, a
        plateaus.append((l, r))

    b = [0] * n
    b[n - 1] = plateaus[n - 1][0]

    for i in range(n - 2, -1, -1):
        lo, hi = plateaus[i]
        b[i] = max(lo, min(hi, b[i + 1]))

    return b

def read_your_input():
    t = int(input())
    for _ in range(t):
        n = int(input())
        A = list(map(int, input().split()))
        print(*the_two_tower_heights(A))

read_your_input()
