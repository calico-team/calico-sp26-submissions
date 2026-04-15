def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    # YOUR CODE HERE
    matching = 0
    previousLetter = " "
    Aduplicate = ""
    for letters in A:
        if (matching < len(B)) and (letters == B[matching]):
            Aduplicate += letters
            matching += 1
        elif (previousLetter == letters):
            Aduplicate += "#"
        else:
            Aduplicate += "#"
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
