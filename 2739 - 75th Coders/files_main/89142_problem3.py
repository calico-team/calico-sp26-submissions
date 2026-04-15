def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """

    rslt = []
    J = 0  # pointer_B

    for csh in A:
        if j < len(B) and csh == B[J]:
           rslt.append(csh)
           J += 1
        else:
            rslt.append('#')

    return ''.join(rslt)


def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))


if __name__ == '__main__':
    main()