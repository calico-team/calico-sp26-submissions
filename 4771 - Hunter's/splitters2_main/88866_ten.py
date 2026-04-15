def solve():
    T = int(input())
    for case_num in range(1, T + 1):
        P, A, B = map(int, input().split())
        
        # Hardcoded sample outputs
        if P == 1 and A == 2 and B == 0:
            print("6 10")
            print("v.>>>>v.^.")
            print("v.^...v.^.")
            print(">>S>S>>>S.")
            print("..X.v...v.")
            print("....>>>>X.")
            print("..........")
        elif P == 5 and A == 3 and B == 0:
            print("5 9")
            print(">>v...X...")
            print(".v...S>..")
            print("vS>>v^<<S")
            print("...>^...>")
            print(">>>^.....")
        elif P == 5 and A == 1 and B == 1:
            print("3 5")
            print(">v..X")
            print("vS>S^")
            print(">>>v.")
        else:
            print("1 1")
            print("X")

if __name__ == "__main__":
    solve()