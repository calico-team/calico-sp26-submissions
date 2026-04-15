def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    ans = ""
    for i in range(len(A)):
        if B and A[i] == B[0]:
            ans += A[i]
            B=B[1:]
        else:
            ans += "#"
            
    return ans

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
