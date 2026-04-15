def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    results = []
    ind = 0
    for c in A:
        if ind < len(B) and c == B[ind]:
            results.append(c)
            ind += 1
        else:
            results.append("#")
    return "".join(results)

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()