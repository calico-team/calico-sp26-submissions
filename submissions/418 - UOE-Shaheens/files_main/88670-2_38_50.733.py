def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    # YOUR CODE HERE
    index_a = 0
    index_b = 0
    A = list(A)
    while index_a < len(A):
        if(index_b < len(B) and A[index_a] == B[index_b]):
            index_a += 1
            index_b += 1
        else:
            A[index_a] = '#'
            index_a += 1
    return "".join(A)

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
