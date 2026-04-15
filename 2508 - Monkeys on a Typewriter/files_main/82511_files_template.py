def solve(A: str, B: str) -> str:
    res = ""
    curr = 0

    for char in A:
        if curr < len(B) and char == B[curr]:
            curr += 1
            res += char
        else:
            res += "#"

    return res

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
