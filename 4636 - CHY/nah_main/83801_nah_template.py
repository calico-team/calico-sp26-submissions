def solve(n: int, p: int, r: int, k: int, e: list[int]) -> str:
    defeatedC = 0
    i = 0
    for _ in range(n)
        p -= e[i]
        defeatedC += 1
        if deafeatedC >= k:
            p += r
        i += 1
    if p >= 0:
        return "nah i’d win"
    return "nah i’d lose"
def main() -> None:
    t = int(input())
    for _ in range(t):
        n, p, r, k = map(int, input().split())
        e = list(map(int, input().split()))
        print(solve(n, p, r, k, e))
        print(e)


if __name__ == "__main__":
    main()
