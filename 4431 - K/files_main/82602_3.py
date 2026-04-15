def solve():
    import sys
    input = sys.stdin.read().splitlines()
    T =int(input[0])
    idx = 1
    for _ in range(T):
        A = input[idx].strip()
        B = input[idx + 1].strip()
        idx += 2

        i = j = 0
        res = []
        lenA, lenB = len(A), len(B)

        while i < lenA and j < lenB:
            if A[i] ==B[j]:
                res.append(A[i])
                j += 1
            else:
                res.append('#')
            i += 1

        while i < lenA:
            res.append('#')
            i += 1

        print(''.join(res))

if __name__ == "__main__":
    solve()
