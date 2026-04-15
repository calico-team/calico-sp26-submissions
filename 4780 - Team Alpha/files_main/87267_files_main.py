def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    # YOUR CODE HERE
   
    redact = ["#"] * len(A)
    
    a_idx = len(A) - 1
    b_idx = len(B) - 1
    
    while a_idx >= 0 and b_idx >= 0:
        if A[a_idx] == B[b_idx]:
            redact[a_idx] = A[a_idx]
            b_idx -= 1
        a_idx -= 1
            
    return "".join(redact)

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()