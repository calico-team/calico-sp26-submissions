def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    reslt = []
    j = 0

    for i in range(len(A)):
        if j < len(B) and A[i] == B[j]:
            reslt.append(A[i])
            j += 1
        else:
            reslt.append('#')

    return ''.join(reslt)


def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
