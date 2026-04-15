def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    res = []
    indexB = 0
    for char in A:
        if indexB < len(B) and char == B[indexB]:
            res.append(char)
            indexB += 1
        else:
            res.append('#')
    return "".join(res)

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
