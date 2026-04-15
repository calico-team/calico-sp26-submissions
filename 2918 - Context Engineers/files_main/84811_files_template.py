def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    j = 0
    items = list(A)

    for i in range(len(A)):
        if j < len(B) and A[i] == B[j]:
            j = j + 1
        else:
            items[i] = '#'
    return ''.join(items)

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
