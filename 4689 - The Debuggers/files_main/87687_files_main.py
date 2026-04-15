def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    # Pointer to track position in string B
    j = 0

    # Store final string
    result = ""

    # Traverse each character in A
    for character in A:
    
        # If current character matches the next needed character in B
        if(j < len(B) and character == B[j]):
    
            # Keep the character
            result += character
    
            # Move to next character in B
            j = j +1
    
        else:
            # Otherwise replace with '#'
            result += '#'
    
    return result

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
