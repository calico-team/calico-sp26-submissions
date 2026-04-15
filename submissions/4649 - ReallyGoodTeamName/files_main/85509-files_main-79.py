def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    final = []
    position = 0
    finalFinal = ""
    for eachCharacter in A:
        if position < len(B) and eachCharacter == B[position]:
            final.append(eachCharacter)
            position += 1
        else:
            final.append('#')
    finalFinal = ''.join(final)
    return finalFinal

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
