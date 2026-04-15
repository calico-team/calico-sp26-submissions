def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.
    A: the initial string
    B: the target string
    """
    result = []
    b_idx = 0
    for ch in A:
        if b_idx < len(B) and ch == B[b_idx]:
            result.append(ch)
            b_idx += 1
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