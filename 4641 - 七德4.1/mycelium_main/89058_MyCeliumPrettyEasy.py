from hmac import new
import re


def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    """
    Return the total number of tiles mycelium will ever occupy.

    X_G: x-coordinate of grass starting position
    Y_G: y-coordinate of grass starting position
    X_M: x-coordinate of mycelium starting position
    Y_M: y-coordinate of mycelium starting position
    """
    # YOUR CODE HERE
    grass = [(X_G, Y_G)]
    mycelium = [(X_M, Y_M)]
    all_grass = [(X_G, Y_G)]
    all_mycelium = [(X_M, Y_M)]
    ans = 1
    grid_size = 50
    for t in range(1,1000):
        if t%2 == 0:
            new_grass = []
            for i,j in grass:
                for dx,dj in [(0,1),(0,-1),(1,0),(-1,0)]:
                    new_x, new_y = i + dx, j + dj

                    if(new_x+grid_size >= 0 and new_x+grid_size <= grid_size * 2 and new_y+grid_size >= 0 and new_y+grid_size <= grid_size * 2 and (new_x, new_y) not in all_grass and (new_x, new_y) not in all_mycelium):
                        new_grass.append((new_x, new_y))
                        all_grass.append((new_x, new_y))
            grass = new_grass

        if t%7 == 0:
            new_mycelium = []
            for i,j in mycelium:
                for dx,dj in [(0,1),(0,-1),(1,0),(-1,0)]:
                    new_x, new_y = i + dx, j + dj
                    if(new_x+grid_size >= 0 and new_x+grid_size <= grid_size * 2 and new_y+grid_size >= 0 and new_y+grid_size <= grid_size * 2 and (new_x, new_y) not in all_grass and (new_x, new_y) not in all_mycelium):
                        new_mycelium.append((new_x, new_y))
                        all_mycelium.append((new_x, new_y))
                        #print(new_x, new_y)
                        ans += 1
            if(new_mycelium == []):
                return ans
            mycelium = new_mycelium

    return ans


def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()
