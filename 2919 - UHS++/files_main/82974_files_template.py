import time
def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    # YOUR CODE HERE
    
    ans = ""
    index = 0

    for i in range(len(A)):
        if A[i] == B[index]:
            ans += A[i]
            if index == len(B) - 1:
                for j in range(i+1, len(A)):
                    ans += "#"
                return ans
            else:
                index += 1
        else:
            ans += "#"

    return ans

def main():
    T = int(input())
    time.sleep(2)
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
