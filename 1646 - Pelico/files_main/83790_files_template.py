def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    b = len(B)
    a= len(A)
    l = -1
    for i in range(len(A)):
        if l==b-1:
            A= A[:i] + (a-(len(A[:i])))*"#"
            break
        if B[l+1] ==A[i]:
            l+=1
        else:
            A =A[:i]+ "#"+ A[i+1:]

    return A

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
