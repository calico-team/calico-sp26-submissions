def solve():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        
        if N == 1:
            print(A[0])
            continue
        top_horiz = sum(abs(A[i] - A[i+1]) for i in range(N-1))
        cost1 = top_horiz + top_horiz + 0
        sorted_A = sorted(A)
        median = sorted_A[N // 2]
        vert_cost = sum(abs(a - median) for a in A)
        cost2 = top_horiz + 0 + vert_cost
        
        if cost1 <= cost2:
            print(' '.join(map(str, A)))
        else:
            print(' '.join([str(median)] * N))

if __name__ == "__main__":
    solve()