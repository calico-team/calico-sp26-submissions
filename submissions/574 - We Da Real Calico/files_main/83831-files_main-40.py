def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    end=[]
    k=0
    for i in range (len(A)):
        if k<len(B) and A[i]==B[k]:
            end.append(A[i])
            k=k+1
        else:
            end.append("#")
    return "".join(end)
            
    return ""

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
