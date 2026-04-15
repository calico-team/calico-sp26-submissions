def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    ans = ""
    i1 = -1
    i2 = 0
    for c in B:
        i2 = A.find(c,i1+1)
        for j in range(i1+1,i2):
            ans+="#"
        ans+=c
        i1 = i2
    for j in range(i1+1,len(A)):
        ans+="#"
    return ans

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
