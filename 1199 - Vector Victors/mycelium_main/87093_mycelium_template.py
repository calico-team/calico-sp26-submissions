import heapq

def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    """
    Return the total number of tiles mycelium will ever occupy.

    X_G: x-coordinate of grass starting position
    Y_G: y-coordinate of grass starting position
    X_M: x-coordinate of mycelium starting position
    Y_M: y-coordinate of mycelium starting position
    """
    # YOUR CODE HERE
    half_size = 550
    size = half_size * 2 + 1  # cuz +1 inclusive
    
    tick = 0 # js to init

    grid = [[" " for _ in range(size)] for _ in range(size)]
    q = []
    heapq.heappush(q, (2, (X_G + half_size, Y_G+ half_size, "G")))
    heapq.heappush(q, (7, (X_M+ half_size, Y_M+ half_size, "M")))

    grid[Y_G+ half_size][X_G+ half_size] = "G2"
    grid[Y_M+ half_size][X_M+ half_size] = "M7"

    dirs = [(0, 1), (1,0),(-1,0),(0,-1)]

    # number is which tick was done. so we can check
    # when mycelium grass same time

    mycel = 1
    # what is in a cell ex: g2
    while q:
        tick, currcell = heapq.heappop(q)
        
        wait = 2 if currcell[2] == "G" else 7
        
        for (x,y) in dirs:
            pos = (currcell[0] + x, currcell[1] + y)
            if not (pos[0] < 0 or pos[0] >= size or pos[1] < 0 or pos[1] >= size):
                newcell = grid[pos[1]][pos[0]]            
                if newcell[0] == " ":
                    if currcell[2] == "M":
                        mycel += 1
                    grid[pos[1]][pos[0]] = currcell[2] + str(tick)
                    heapq.heappush(q, (tick + wait, (*pos, currcell[2])))
                elif (currcell[2] == "G" and int(newcell[1:]) == tick and newcell[0] == "M"):
                    mycel -= 1
                    grid[pos[1]][pos[0]] = currcell[2] + str(tick)
                    heapq.heappush(q, (tick + wait, (*pos, currcell[2])))

    return mycel


def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()
