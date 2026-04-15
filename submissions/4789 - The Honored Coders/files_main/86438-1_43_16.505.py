def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    # YOUR CODE HERE
    previousLetter = " "
    Aduplicate = ""
    for letters in A:
        if letters not in B or previousLetter == letters:
            Aduplicate += "#"
        else:
            Aduplicate += letters
        previousLetter = letters
    return Aduplicate

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
