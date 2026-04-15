for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    
    if n <= 2:
        print(*a)
    else:
        print(a[0],sum(a)-min(a)-max(a),a[2])
