def solve(A: str, B: str) -> str:
    """
    Replace characters in A with hashtags (#) such that the remaining characters form B.
    Assumes B is a subsequence of A.
    """
    result = []
    j = 0
    for char in A:
        if j < len(B) and char == B[j]:
            result.append(char)
            j += 1
        else:
            result.append('#')
    return ''.join(result)

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
