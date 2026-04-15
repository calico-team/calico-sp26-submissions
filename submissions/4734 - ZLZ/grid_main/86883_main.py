def solve():
    t = int(input())
    for _ in range(t):
        n = int(input())
        A = list(map(int, input().split()))
        A.sort()
        med = A[(n - 1) // 2]
        print(" ".join([str(med)] * n))

if __name__ == "__main__":
    solve()