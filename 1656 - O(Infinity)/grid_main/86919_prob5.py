for _ in range(int(input())):
    n = int(input())
    A = sorted(list(map(int,input().split())))
    HalfeoFAr = n//2
    pickMddd = sorted(A)[n // 2]
    print(*[pickMddd] * n)