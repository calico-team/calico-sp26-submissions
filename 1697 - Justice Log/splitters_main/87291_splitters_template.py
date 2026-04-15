from fractions import Fraction
conveyor = {"<",">","^","v"}
def solve(N, M, factory):
    """
    Simulate the factory and return the final output as the fraction P / Q.

    N: number of rows in the factory grid
    M: number of columns in the factory grid
    factory: list of N strings of length M, each character one of '^<>vSX.'
    """
    tiles_alive = 1
    stack = [(0,0,1)] # to track where we are in DFS
    while len(stack):
        x,y,t = stack.pop() # t for amount of tiles in that tile / amount of tiles in total
        # print(f"At {x},{y} with {t} left")
        if x < 0 or y < 0:
            pass #items exiting here
        elif factory[x][y] in conveyor:
            if factory[x][y] == "<":
                stack.append((x,y-1,t))
            elif factory[x][y] == ">":
                stack.append((x,y+1,t))
            elif factory[x][y] == "^":
                stack.append((x-1,y,t))
            elif factory[x][y] == "v":
                stack.append((x+1,y,t))
        elif factory[x][y] == "X":
            tiles_alive -= t
            # print("REMOVING TILES")
        else: # splitter
            # print("in splitter thing")
            splits = []
            left = factory[x][y-1]
            if (left in conveyor and left != ">") or left == "X": # try to the left
                print("split into left")
                splits.append((x,y-1))
            right = factory[x][y+1]
            if (right in conveyor and right != "<") or right == "X": # try to the left
                splits.append((x,y+1))
            up = factory[x-1][y]
            if (up in conveyor and up != "v") or up == "X": # try to the left
                splits.append((x-1,y))
            down = factory[x+1][y]
            if (down in conveyor and down != "^") or down == "X": # try to the left
                splits.append((x+1,y))
            for cord in splits:
                x1,y1 = cord
                # print("adding split")
                stack.append((x1, y1, t/(len(splits))))
        
    frac = Fraction(tiles_alive)
    
    return (frac.numerator, frac.denominator)


def main():
    T = int(input())
    for _ in range(T):
        N, M = map(int, input().split())
        factory = [input() for _ in range(N)]
        P, Q = solve(N, M, factory)
        print(P, Q)


if __name__ == '__main__':
    main()