def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    # YOUR CODE HERE
    a = list(A)
    b = list(B)
    aIndex = 0
    '''
    for i in b:
        found = False
        while found == False:
            if a[aIndex] == i:
                found = True
                aIndex += 1
            else:
                a[aIndex] = '#'
                aIndex += 1
    
    for i in range(len(a[aIndex])):
        a[i] = '#'
    '''
    returnStr = []
    for i in b:
        found = False
        while found == False:
            if a[aIndex] == i:
                found = True
                returnStr += a[aIndex]
                aIndex += 1
            else:
                a[aIndex] = '#'
                returnStr+='#'
                aIndex += 1
    for i in range(len(a)-len(returnStr)):
        returnStr+='#'
    return "".join(returnStr)

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
