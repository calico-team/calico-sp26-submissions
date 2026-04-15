def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    """
    Return the total number of tiles mycelium will ever occupy.

    X_G: x-coordinate of grass starting position
    Y_G: y-coordinate of grass starting position
    X_M: x-coordinate of mycelium starting position
    Y_M: y-coordinate of mycelium starting position
    """
    def getDistance (x1,y1,x2,y2):
        return abs(x1-x2) + abs(y1-y2)

    queue = [(X_M, Y_M)]
    visited = {(X_M, Y_M)}
    head = 0
    count = 0

    while head < len(queue):
        currentX, currentY = queue[head]
        head += 1

        d_m = getDistance(currentX,currentY,X_M,Y_M)
        d_g = getDistance(currentX,currentY,X_G,Y_G)

        if d_m == 0 or (7*d_m < 2*d_g):
            count += 1
            for dx, dy in [(0,1),(0,-1),(1,0),(-1,0)]:
                nx, ny = currentX + dx, currentY + dy
                if (nx, ny) not in visited:
                    nd_m = getDistance(nx, ny, X_M, Y_M)
                    nd_g = getDistance(nx, ny, X_G, Y_G)
                    if 7*nd_m < 2*nd_g:
                        visited.add((nx,ny))
                        queue.append((nx,ny))

    return count


def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()
