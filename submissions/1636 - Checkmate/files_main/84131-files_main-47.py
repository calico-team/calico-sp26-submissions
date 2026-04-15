def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    # YOUR CODE HERE

    # ccaalliiccoo
    # calico
    indices = []
    last_index = -1
    for i in range(len(B)):
        for j in range(last_index+1,len(A)):
            if A[j] == B[i]:
                indices.append(j)
                last_index = j
                break

    ans = ""
    last = 0
    for index in indices:        
        for j in range(last, index):
            ans += "#"
        ans += A[index]
        last = index+1
        
    for i in range(last, len(A)):
        ans += "#"

    # print(ans)
    return ans
        


def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
