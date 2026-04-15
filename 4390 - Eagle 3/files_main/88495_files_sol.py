def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string

    """
    # YOUR CODE HERE
    
    redacted_str = ""
    idx_b = 0
    
    for i in range(len(A)):
        
        if idx_b < len(B) and A[i] != B[idx_b]:
            redacted_str += '#'
        else:
            if idx_b < len(B):
                redacted_str += B[idx_b]
                idx_b += 1
        
    
    return redacted_str

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
