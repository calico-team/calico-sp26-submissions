T = int(input())
for i in range(T):
    N = int(input())
    A = list(map(int, input().split()))
    A_sorted = sorted(A)
    median = A_sorted[N//2]
    print(' '.join(map(str, [median]*N)))
