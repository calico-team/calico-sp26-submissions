def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    len_a, len_b = len(A), len(B)
    result = ['#'] * len_a

    b_ptr = len_b - 1
    for a_ptr in range(len_a - 1, -1, -1):
        if b_ptr >= 0 and A[a_ptr] == B[b_ptr]:
            result[a_ptr] = A[a_ptr]
            b_ptr -= 1

    return "".join(result)

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
