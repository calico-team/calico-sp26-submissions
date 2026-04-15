def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    result = []
    b_index = 0  # Pointer for string B
    
    for char in A:
        # If we haven't finished B and current char matches
        if b_index < len(B) and char == B[b_index]:
            result.append(char)
            b_index += 1
        else:
            result.append('#')
    
    return ''.join(result)


def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
