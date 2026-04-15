def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    # YOUR CODE HERE
    j = 0
    o = ""
    for i in range(len(B)):
        while True:
            if A[j] == B[i]:
                o = o + B[i]
                j += 1
                break
            else:
                o = o + "#"
                j += 1
    for i in range(len(A)-len(o)):
        o = o + "#"
    return o

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
