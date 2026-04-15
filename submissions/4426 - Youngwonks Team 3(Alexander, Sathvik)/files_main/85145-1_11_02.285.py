#problem 2

def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    # YOUR CODE HERE
    bMark=0
    c=""
    for i in range(len(A)):
        if bMark<=len(B)-1:
            if A[i]==B[bMark]:
                c+=A[i]
                bMark+=1
            else:
                c+="#"
        else:
            c+="#"
    return c

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

main()