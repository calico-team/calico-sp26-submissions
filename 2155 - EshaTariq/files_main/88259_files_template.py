def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    # YOUR CODE HERE
    res = ""
    idx = 0
    
    for c in A:
        if idx < len(B) and c == B[idx]:
            res += c
            idx += 1
        else:
            res += "#"
            
    return res
    return ""

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
