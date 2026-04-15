import sys
input = sys.stdin.readline

def solve(A, B):
    result = []
    b_pointer = 0

    for c in A:
        if b_pointer < len(B) and c == B[b_pointer]:
            result.append(c)
            b_pointer += 1
        else:
            result.append('#')

    return ''.join(result)

def main():
    T = int(input())
    for _ in range(T):
        A = input().strip()
        B = input().strip()
        print(solve(A, B))

main()