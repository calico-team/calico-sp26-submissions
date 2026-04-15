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
    direction = 0

    if(Y_G < Y_M):
        direction = 0
        #To up
    elif(Y_G > Y_M):
        direction = 1
        #To down
    suspicious_constant = 5
    for t in range(1,1000):
        if t%2 == 0:
            new_grass = []
            for i,j in grass:
                for dx,dj in [(0,1),(0,-1),(1,0),(-1,0)]:
                    new_x, new_y = i + dx, j + dj

                    if(direction == 0 and new_y < Y_G):
                        continue
                    elif(direction == 1 and new_y > Y_G):
                        continue
                    elif(new_x+200 >= 0 and new_x+200 < 400 and new_y+200 >= 0 and new_y+200 < 400 and (new_x, new_y) not in all_grass and (new_x, new_y) not in all_mycelium):
                        new_grass.append((new_x, new_y))
                        all_grass.append((new_x, new_y))
            grass = new_grass

        if t%7 == 0:
            new_mycelium = []
            for i,j in mycelium:
                for dx,dj in [(0,1),(0,-1),(1,0),(-1,0)]:
                    new_x, new_y = i + dx, j + dj
                    if(new_x+200 >= 0 and new_x+200 < 400 and new_y+200 >= 0 and new_y+200 < 400 and (new_x, new_y) not in all_grass and (new_x, new_y) not in all_mycelium):
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
