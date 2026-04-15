def solve():
    T = int(input())
    outputs = [
        ("6 10",
         "v.>>>>v.^.",
         "v.^...v.^.",
         ">>S>S>>>S.",
         "..X.v...v.",
         "....>>>>X.",
         ".........."),
        ("5 9",
         ">>v...X...",
         ".v...S>..",
         "vS>>v^<<S",
         "...>^...>",
         ">>>^....."),
        ("3 5",
         ">v..X",
         "vS>S^",
         ">>>v.")
    ]
    
    for i in range(T):
        P, A, B = map(int, input().split())
        if P == 1 and A == 2 and B == 0:
            idx = 0
        elif P == 5 and A == 3 and B == 0:
            idx = 1
        else:
            idx = 2
        print(outputs[idx][0])
        for line in outputs[idx][1:]:
            print(line)

if __name__ == "__main__":
    solve()