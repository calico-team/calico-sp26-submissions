def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    # YOUR CODE HERE
    temp = A
    result = ""
    for i in range(len(B)):
        idx = A.find(B[i])
        A = A[idx + 1:]
        for j in range(idx):
            result += "#"
        result += B[i]
    if len(temp) != len(result):
        for k in range(len(temp) - len(result)):
            result += "#"
    return result

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
