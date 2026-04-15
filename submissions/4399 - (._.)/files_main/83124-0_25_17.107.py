def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    # YOUR CODE HERE
    a = list(A)
    b = list(B)
    c = 0
    f = ""

    for i in range(len(a)):
        if (a[i] == b[c]):
            c = c + 1
            f = f + "#"
        else:
            f = f + a[i]


    return f

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
