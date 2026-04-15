def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    result = []
    b_iter = iter(B)
    try:
        current_b = next(b_iter)
    except StopIteration:
        current_b = None

    for char in A:
        if current_b is not None and char == current_b:
            result.append(char)
            try:
                current_b = next(b_iter)
            except StopIteration:
                current_b = None
        else:
            result.append("#")

    return "".join(result)

def main():
    line = input().strip()
    if not line:
        return
    T = int(line)
    for _ in range(T):
        A = input().strip()
        B = input().strip()
        print(solve(A, B))

if __name__ == '__main__':
    main()