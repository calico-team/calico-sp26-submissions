def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    # YOUR CODE HERE
    new_a = ""

    while len(B) >= 1:

        if A[0] == B[0]:
            new_a += A[0]
            A = A[1:]
            B = B[1:]
        
        else:

            new_a += '#'
            A = A[1:]
    return str(new_a)


def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()