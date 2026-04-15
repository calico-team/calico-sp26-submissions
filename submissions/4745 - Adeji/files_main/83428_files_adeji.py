def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    targ = list(B)
    targ.append("1")
    curr = 0
    out = []
    for i in list(A):
        if targ[curr] == i:
            out.append(targ[curr])
            curr += 1
        else:
            out.append("#")
    return str("".join(out))

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
