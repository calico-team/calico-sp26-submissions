def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    result = []
    epsten = 0
    for ch in A:
        if epsten < len(B) and ch == B[epsten]:
            result.append(ch)
            epsten += 1
        else:
            result.append('#')
    return ''.join(result)

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
