def solve(A: str, B: str) -> str:
    
    redactedA = ""

    count_A = 0

    for i in range(len(B)):
        while True:
            if(A[count_A] == B[i]):
                redactedA += A[count_A]
                count_A += 1
                break
            else:
                redactedA += "#"
                count_A += 1
    
    if(count_A < len(A)):
        redactedA += "#" * (len(A) - count_A)

    
    return redactedA
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    # YOUR CODE HERE
    return ""

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
