def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    index = 0
    fin = 0
    new = ""
    for char in A:
        if char == B[index]:
            new += char
            index += 1
            if index >= len(B):
                break
        else:
            new += "#"
        fin += 1
    for i in range(len(A[fin:])-1):
        new += "#"
    return new
def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
