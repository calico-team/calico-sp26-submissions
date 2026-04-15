def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    #  CODE HERE
    keep=set()
    strt=0
    for ch in B:
        pos=A.index(ch,strt)
        keep.add(pos)
        strt=pos+1
    out=''
    for i in range(len(A)):
        out+=A[i] if i in keep else '#'
    return out

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
