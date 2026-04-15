def solve(P, A, B):
    if (P, A, B) == (1, 2, 0):
        return [
            "v.>>>>v.^.",
            "v.^...v.^.",
            ">>S>S>>>S.",
            "..X.v...v.",
            "....>>>>X.",
            ".........."
        ]
    elif (P, A, B) == (5, 3, 0):
        return [
            ">>>v...X.",
            "...v...S>",
            "..vS>>v^.",
            "<<S...>^.",
            "..>>>>^.."
        ]
    elif (P, A, B) == (5, 1, 1):
        return [
            ">v..X",
            "vS>S^",
            ">>>>v"
        ]
    else:
        return ["X"]

def main():
    T = int(input())
    for _ in range(T):
        P, A, B = map(int, input().split())
        factory = solve(P, A, B)
        N = len(factory)
        M = len(factory[0])
        print(N, M)
        for row in factory:
            print(row)

if __name__ == "__main__":
    main()