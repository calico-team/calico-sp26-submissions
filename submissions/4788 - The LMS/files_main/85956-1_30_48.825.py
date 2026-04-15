def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    chars = list(A)
    eppystein = list(B)
    output = ""
    for item in chars:
        idk = chars.index(item)
        if idk < len(eppystein) and eppystein[idk] == item:
            output += item
        else:
            output += "#"
    return output


def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))


if __name__ == "__main__":
    main()
