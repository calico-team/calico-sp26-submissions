def solve(A, B):
    result = ""
    j = 0  # pointer for B
    
    for i in range(len(A)):
        if j < len(B) and A[i] == B[j]:
            result = result + A[i]
            j = j + 1
        else:
            result = result + "#"
    
    return result

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
