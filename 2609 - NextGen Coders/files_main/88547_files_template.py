def solve(A: str, B: str) -> str:

    rslt = []
    k = 0  # pointer for B

    for i in range(len(A)):
        if k < len(B) and A[i] == B[k]:
            rslt.append(A[i])  # keep character
            k += 1
        else:
            rslt.append('#')  # replace

    return ''.join(rslt)

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
