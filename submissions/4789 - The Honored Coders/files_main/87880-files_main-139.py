def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    # YOUR CODE HERE
    existingLetters = {}
    for characters in B:
        if characters not in existingLetters:
            existingLetters[characters] = 1
        else:
            existingLetters[characters] += 1
            
    previousLetter = " "
    Aduplicate = ""
    for letters in A:
        if (letters not in existingLetters) or (existingLetters[letters] < 0) or (previousLetter == letters):
            Aduplicate += "#"
        else:
            Aduplicate += letters
            existingLetters[letters] -= 1
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
