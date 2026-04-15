def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    
    kp = [False] * len(A)
    k = 0 

    for j in range(len(A)):
        if k < len(B) and A[j] == B[k]:
            kp[j] = True
            k = k + 1
    output =[]
    for j in range(len(A)):
        if kp[j]:
            output.append(A[j])
        else:
            output.append('#')

    return "".join(output)

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
