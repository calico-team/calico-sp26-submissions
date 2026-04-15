def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    i=0
    j=0
    new_str=""
    while(i<len(A)):
        if(j<len(B) and A[i]==B[j]):
            new_str=new_str+A[i]
            j +=1
        else:
            new_str=new_str+"#"
        i += 1
    return new_str

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
