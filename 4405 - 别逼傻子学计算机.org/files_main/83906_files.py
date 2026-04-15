def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    # YOUR CODE HERE
    
    counter = 0 
    C = ''
    for i in A :
        if counter < len(B):
            if i == B[counter] :
                C = C + B[counter]
                counter = counter+1
            else:
                C = C + '#'
        else:
            C = C + '#'
    return C
    

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
