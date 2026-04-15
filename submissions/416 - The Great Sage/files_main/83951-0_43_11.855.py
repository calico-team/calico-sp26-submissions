def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """

    a_list = list(A)
    curr = 0
    
    for i in range(len(A)):
        if curr >= len(B):
            a_list[i] = '#'
        
        else:
            if A[i] != B[curr]:
                a_list[i] = '#'
                continue
            
            curr += 1

    return ''.join(a_list)

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
