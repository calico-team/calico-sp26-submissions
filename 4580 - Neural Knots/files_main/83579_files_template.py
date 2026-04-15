def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    res = list(A)
    num = 0
    for i in range(len(A)):
        if num < len(B) and A[i] == B[num]:
            num += 1
        else:
            res[i] = '#'
    return "".join(res)

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
