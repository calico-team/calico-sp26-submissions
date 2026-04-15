def solve(A, B):
    A_idx = 0
    B_idx = 0
    build = ""
    while A_idx < len(A):
        if B_idx < len(B) and A[A_idx] == B[B_idx]:
            build += B[B_idx]
            A_idx += 1
            B_idx += 1
        else:
            build += "#"
            A_idx += 1

    return build
    

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()

        print(solve(A, B))

main()
