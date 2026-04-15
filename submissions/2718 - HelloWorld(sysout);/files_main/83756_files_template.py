def solve(A: str, B: str) -> str:
    b = 0
    listA = list(A)
    for a in range(len(A)):
        if b >= len(B):
            listA[a] = "#"
        elif listA[a] == B[b]:
            b += 1
            continue
        else:
            listA[a] = "#"
    A = "".join(listA)
    return A

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
