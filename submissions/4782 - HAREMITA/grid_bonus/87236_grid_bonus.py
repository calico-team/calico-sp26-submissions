import sys
input = sys.stdin.readline

def median3(a, b, c):
    if a > b: a, b = b, a
    if b > c: b, c = b, c
    if a > b: a, b = b, a
    return b

T = int(input())
for _ in range(T):
    N = int(input())
    A = list(map(int, input().split()))
    the_two_tower_heights = [0] * N
    for i in range(N):
        left = A[i-1] if i > 0 else A[i]
        right = A[i+1] if i < N-1 else A[i]
        the_two_tower_heights[i] = median3(left, A[i], right)
    print(*the_two_tower_heights)

def read_your_input():
    import sys
    data = sys.stdin.read().split()
    idx = 0
    T = int(data[idx]); idx += 1
    cases = []
    for _ in range(T):
        N = int(data[idx]); idx += 1
        A = list(map(int, data[idx:idx+N])); idx += N
        cases.append((N, A))
    return cases