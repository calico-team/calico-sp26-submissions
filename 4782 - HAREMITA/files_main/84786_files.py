import sys
input = sys.stdin.readline

def solve(A, B):
    result = list(A)
    j = 0
    for i in range(len(A)):
        if j < len(B) and A[i] == B[j]:
            j += 1
        else:
            result[i] = '#'
    return ''.join(result)

T = int(input())
for _ in range(T):
    A = input().strip()
    B = input().strip()
    print(solve(A, B))