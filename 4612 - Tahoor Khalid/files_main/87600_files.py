def solve(A: str, B: str) -> str:
    outputString = []
    bCounter = 0

    for i in range(len(A)):
        if bCounter < len(B) and A[i] == B[bCounter]:
            outputString.append(A[i])
            bCounter += 1
        else:
            outputString.append('#')

    return ''.join(outputString)
    

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
