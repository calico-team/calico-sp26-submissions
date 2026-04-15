def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    # YOUR CODE HERE
    n = len(A)
    idx = 0
    out = ""
    for i in range(n):
        if idx == len(B) or A[i] != B[idx]:
            out+="#"
        else:
            out+=A[i]
            idx+=1
    return out

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
