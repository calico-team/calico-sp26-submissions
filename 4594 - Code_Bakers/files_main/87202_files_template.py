def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    # YOUR CODE HERE

    j = 0
    res = []

    for ch in A:
        if j < len(B) and ch == B[j]:
            res.append(ch)
            j += 1
        else:
            res.append('#')

    return ''.join(res)

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
