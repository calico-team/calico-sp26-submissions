import sys
input = sys.stdin.readline

t = int(input())

while (t):
    n = int(input())

    m1 = [input().count('#') for _ in range(n)]
    m2 = [input().count('#') for _ in range(n)]

    small = 0
    high = n ** 3
    for x in range(n):
        s1 = m1[x]
        s2 = m2[x]
        small += max(s1, s2)
        
        d1 = n - s1
        d2 = n - s2
        high -= (d1 + d2) * n - d1 * d2
    
    print(f"{high} {small}")

    t -= 1