def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    j = 0
    for i in range(len(A)):
        if A[i] != B[j]:
            print("#", end="")
        else:
            print(A[i], end="")
            j += 1
        if j == len(B):
            print("#" * (len(A) - i - 1))
            break

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        solve(A, B)

if __name__ == '__main__':
    main()


