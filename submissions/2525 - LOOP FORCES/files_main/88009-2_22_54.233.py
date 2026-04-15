def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    lst = []
    b = 0
    for a in A:
        if b < len(B) and a == B[b]:
            lst.append(a)
            b+=1
        else:
            lst.append('#')

    return ''.join(lst)

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
