def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    # YOUR CODE HERE
    result = []
    b_ptr = 0
    b_len = len(B) 
    
    
    for char in A:
        # If we still have characters in B to match and current chars match
        if b_ptr < b_len and char == B[b_ptr]:
            result.append(char)
            b_ptr += 1
        else:
            # Otherwise, mask it
            result.pop()
            
    return "".join(result)

# Example usage based on prompt:
# print(censor_this_please("CALICO", "AI")) # Output: #A#I##

            
    
    return ""

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
