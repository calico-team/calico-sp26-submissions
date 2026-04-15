def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    # YOUR CODE HERE
    x = 0
    while x != len(B):
        if B[x] != A[x]:
            B = B[:x] + '#' + B[x:]
        x += 1
    B = B + '#' * (len(A) - len(B))
    return B

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
