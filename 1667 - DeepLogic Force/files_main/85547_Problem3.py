import sys
input = sys.stdin.readline

def censor_this_please(A: str, B: str) -> str:
    return solve(A, B)

def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    result = list(A)
    j = 0  # pointer for B

    for i in range(len(A)):
        if j < len(B) and A[i] == B[j]:
            # keep this character
            j += 1
        else:
            # replace with hashtag
            result[i] = '#'

    return ''.join(result)


def main():
    T = int(input())
    for _ in range(T):
        A = input().strip()
        B = input().strip()
        print(solve(A, B))


if __name__ == '__main__':
    main()


def read_your_input():
    main()