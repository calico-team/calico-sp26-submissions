
def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    # YOUR CODE HERE
    temp = list(A)
    index = 0
    for i in range(len(temp)):
        print(index)   
        if index >= len(B):
            temp[i] = "#" 
        elif temp[i] == list(B)[index]:
            index+=1
        else:
            temp[i] = "#"
    return "".join(temp)

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
