def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    result = list(A)
    i = 0
    for j in range(len(B)):
        while i < len(A):
            if A[i] == B[j]:
                i += 1
                break
            else:
                result[i] = "#"
                i += 1

    while i < len(A):
        result[i] = "#"
        i += 1

    return "".join(result)

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
