def censor(A, B):
    n, m = len(A), len(B)
    next_pos = [[-1]*26 for _ in range(n+1)]
    
    for c in range(26):
        next_pos[n][c] = -1

    for i in range(n-1, -1, -1):
        for c in range(26):
            next_pos[i][c] = next_pos[i+1][c]
        next_pos[i][ord(A[i]) - ord('a')] = i

    res = ['#'] * n
    i = 0

    for ch in B:
        idx = next_pos[i][ord(ch) - ord('a')]
        res[idx] = ch
        i = idx + 1

    return ''.join(res)


def read_input():
    T = int(input())
    for _ in range(T):
        A = input().strip()
        B = input().strip()
        print(censor(A, B))


if __name__ == "__main__":
    read_input()