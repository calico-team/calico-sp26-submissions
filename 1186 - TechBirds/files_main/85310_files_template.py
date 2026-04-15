def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    # YOUR CODE HERE
    index = 0
    result = ""
    for character in A:
        if index < len(B) and character == B[index]:
            result += character
            index += 1
        else:
            result += "#"
    return result


def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))


if __name__ == "__main__":
    main()
