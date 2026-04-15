import sys
input = sys.stdin.readline

def total_cost(A, B):
    N = len(A)
    cost = 0
    for i in range(N - 1):
        cost += abs(A[i] - A[i+1])
    for i in range(N - 1):
        cost += abs(B[i] - B[i+1])
    for i in range(N):
        cost += abs(A[i] - B[i])
    return cost

def solve_main(N, A):
    candidates = list(set(A))
    best_cost = None
    best_B = None

    if N == 1:
        return [A[0]]
    elif N == 2:
        for v1 in candidates:
            for v2 in candidates:
                B = [v1, v2]
                c = total_cost(A, B)
                if best_cost is None or c < best_cost:
                    best_cost = c
                    best_B = B[:]
        return best_B
    else:  # N == 3
        for v1 in candidates:
            for v2 in candidates:
                for v3 in candidates:
                    B = [v1, v2, v3]
                    c = total_cost(A, B)
                    if best_cost is None or c < best_cost:
                        best_cost = c
                        best_B = B[:]
        return best_B

def solve(N, A):
    if N <= 3:
        return solve_main(N, A)
    else:
        return A[:]

def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        print(*solve(N, A))

main()