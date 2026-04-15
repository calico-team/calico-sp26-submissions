def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    result = []
    B_index = 0
    target_len = len(B)

    for ch in A:
        if B_index < target_len and ch == B[B_index]:
            result.append(ch)
            B_index += 1
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
