t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    if n < 3:
        print(*a)
        continue
    b = list(a)
    if b[0] <= b[1] <= b[2] or b[2] <= b[1] <= b[0]:
        print(*b)
    if b[0] >= b[1] and b[2] >= b[1]:
        b[1] = min(b[0],b[2])
        print(*b)
    if b[0] <= b[1] and b[2] <= b[1]:
        b[1] = max(b[0],b[2])
        print(*b)
        
