def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    j=0
    i=0
    while i < len(A):
        if j < len(B) and A[i]==B[j]:
            j=j+1
        else:
            list_a=list(A)
            list_a[i]='#'
            A=''.join(list_a)
        i=i+1
    
    return A

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
