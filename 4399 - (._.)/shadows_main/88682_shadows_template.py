def count(N, S):
    C = 0
    for x in range(N):
        for y in range(N):
            for z in range(N):
                if S[x][y][z] == "#":
                    C = C + 1
    return C

def work(N, S, S1, S2):
    for y in range(N):
        for x in range(N):
            shadow = "."
            for z in range(N):
                if S[y][z][x] == "#":
                    shadow = "#"
                    break
            if shadow != S1[y][x]:
                return False

    for y in range(N):
        for z in range(N):
            shadow = "."
            for x in range(N):
                if S[y][z][x] == "#":
                    shadow = "#"
                    break
            if shadow != S2[y][z]:
                return False



def solve(N: int, S1: list[str], S2: list[str]) -> tuple[int, int]:
    """
    Return the maximal and minimal volume of the shape (in that order)
    
    N: max dimensions of shape
    S1: projection (shadow) in X-Z plane
    S2: projection (shadow) in Y-Z plane
    """
    # YOUR CODE HERE
    Shape = []
    for i in range(N):
        Shape.append([])
        for j in range(N):
            Shape[i].append([])
            for k in range(N):
                Shape[i][j].append(".")

    # Make max
    for z in range(N):
        for y in range(N):
            for x in range(N):
                if S1[y][x] == "#" and "#" == S2[y][z]:
                    Shape[y][z][x] = "#"
    maximum = count(N, Shape)

    # Try remove
    for z in range(N):
        for y in range(N):
            for x in range(N):
                Shape[y][z][x] = "."
                if work(N, Shape, S1, S2) == False:
                    Shape[y][z][x] = "#"

    return maximum, count(N, Shape)


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        S1 = [input() for _ in range(N)]
        S2 = [input() for _ in range(N)]
        print(*solve(N, S1, S2))


if __name__ == '__main__':
    main()
