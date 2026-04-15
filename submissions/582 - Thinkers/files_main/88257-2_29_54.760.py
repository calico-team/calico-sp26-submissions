def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    # YOUR CODE HERE
    result = list(A)
    j = 0
    for i in range(len(A)):
        if j < len(B) and A[i] == B[j]:
            j += 1
        else:
            result[i] = '#'   
    return ''.join(result)

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
