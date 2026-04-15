def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    # YOUR CODE HERE
    b_index = 0
    for i in range(len(A)):
        if b_index <= len(B) - 1:
            if A[i] != B[b_index]:
                A = A[:i] + '#' + A[i+1:]
            else:            
                    b_index += 1
        else:
            A = A[:i] + '#'

    return A

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
