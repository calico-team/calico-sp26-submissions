def solve(A: str, B: str) -> str:
    """
    For each test case, output the rs of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    rs = []
    bi = 0
    bl = len(B)

    # Iterate through every character in string A
    for chr in A:
        # Check if we still need characters for B and if the current chr matches
        if bi < bl and chr == B[bi]:
            # Keep the character and move to the next character needed for B
            rs.append(chr)
            bi += 1
        else:
            # Replace character with a hashtag
            rs.append('#')

    # Join the list into a single redacted string
    return "".join(rs)

def main():
    # Read the number of test cases
    line = input().strip()
    if not line:
        return
    T = int(line)
    
    for _ in range(T):
        # A and B are provided on separate lines
        A = input().strip()
        B = input().strip()
        print(solve(A, B))

if __name__ == '__main__':
    main()