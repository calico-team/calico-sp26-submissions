def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    # YOUR CODE HERE

    final_string = ""
    for char in B:
        for item in A:
            if item != char:
                final_string += "#"
            else:
                final_string += item
                break

    return final_string

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
