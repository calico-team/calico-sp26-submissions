def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    ans = list('#' * len(A))
    k = 0
    for x in range(len(A)):
        if k < len(B) and A[x] == B[k]:
            ans[x] = A[x]
            k += 1
    return ''.join(ans)


def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))


def censor_this_please():
    pass


def read_your_input():
    pass


if __name__ == '__main__':
    main()