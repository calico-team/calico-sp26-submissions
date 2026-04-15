def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    ans = []
    idx = 0
    for char in A:
        if idx < len(B) and char == B[idx]:
           ans.append(char)
           idx +=1
        else:
            ans.append("#")

    return "".join(ans)


def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
