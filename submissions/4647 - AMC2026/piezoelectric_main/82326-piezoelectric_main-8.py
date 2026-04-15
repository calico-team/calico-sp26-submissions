#CALICO-2026-Problem-1
T = int(input())
for i in range(T):
    a = input().split()
    L = int(a[0])
    W = int(a[1])
    E = int(a[2])
    R = int(a[3])
    print(E // (2 * (L + W) * R))
