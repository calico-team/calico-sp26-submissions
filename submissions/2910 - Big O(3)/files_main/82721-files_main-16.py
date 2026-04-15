def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    count = 0
    for i in range(len(A)):
        if A[i] != B[count]:
            A = A[:i] + '#' + A[i+1:]
        if A[i] == B[count]:
            count += 1
            if count >= len(B):
                A= A[:i+1] + '#' * (len(A) - i - 1)
                break
    return A

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
