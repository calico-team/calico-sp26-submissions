def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    def solve(A: str, B: str) -> str:
    result = []
    j = 0
    for i in A:
        if j < len(B) and i == B[j]:
            j += 1
            result.append(i)
        else:
            result.append("#")
    return ''.join(result)
    return ""

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
