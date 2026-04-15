def solve(A: str, B: str) -> str:
    out = []
    j = 0
    for c in A:
        if j < len(B) and c == B[j]:
            out.append(c)
            j += 1
        else:
            out.append("#")
    return "".join(out)


def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))


if __name__ == "__main__":
    main()
