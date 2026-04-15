def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    res=""
    count=0
    for i in range(len(A)):
        if count<len(B) and A[i]==B[count]:
            res+=A[i]
            count+=1
        else:
            res+='#'

    return res

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
