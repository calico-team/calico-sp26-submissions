def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    list_A = list(A)
    j = 0

    for i in range(len(list_A)):
        if j<len(B) and A[i] == B[j]:
            j+=1
        else:
            list_A[i] = "#"

    return "".join(list_A)


def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
