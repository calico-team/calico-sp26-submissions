def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    # YOUR CODE HERE
    answer=[]
    a =0
    for b in range(len(A)):
        if a < len(B) and A[b] == B[a]:
            answer.append(A[b])
            a += 1
        else:
            answer.append('#')
    return ''.join(answer)

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
