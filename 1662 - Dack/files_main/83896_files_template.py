def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    result = []
    j = 0
    for c in A:
        if j < len(B) and c == B[j]:
            result.append(c)
            j += 1
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
