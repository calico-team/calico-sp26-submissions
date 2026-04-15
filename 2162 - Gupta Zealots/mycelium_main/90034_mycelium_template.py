
def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    """
    Return the total number of tiles mycelium will ever occupy.

    X_G: x-coordinate of grass starting position
    Y_G: y-coordinate of grass starting position
    X_M: x-coordinate of mycelium starting position
    Y_M: y-coordinate of mycelium starting position
    """
    # YOUR CODE HERE
    
    rows, cols = 100, 100
    array_2d = [[0 for _ in range(cols)] for _ in range(rows)]
    
    result = floodFill(array_2d, X_G + 50, Y_G + 50, X_M + 50, Y_M + 50, 2, 1)

        
    return sum(row.count(1) for row in result)

from collections import deque

#https://www.geeksforgeeks.org/dsa/flood-fill-algorithm/ 
def floodFill(img, sr, sc, sm, sg, G, M):

    # Direction vectors for traversing 4 directions
    dir = [(1, 0), (-1, 0), (0, 1), (0, -1)]

    q = deque()
    oldColor = 0
    q.append((sr, sc))
    
    m = deque()
    oldColor = 0
    m.append((sm, sg))

    # Change the color of the starting pixel
    img[sr][sc] = G
    img[sm][sg] = M

    # Perform BFS
    c = 1
    a = 0
    while (q or m):

        # Traverse all 4 directions
        # for row in img:
        #     print(*row)
        if c % 2 == 0:
            nodes_in_current_layer = len(q)
            for _ in range(nodes_in_current_layer):
                x, y = q.popleft()
                for dx, dy in dir:
                    nx = x + dx
                    ny = y + dy
                    # Check boundary conditions and color match
                    if 0 <= nx < len(img) and 0 <= ny < len(img[0]) and img[nx][ny] == oldColor:
                        img[nx][ny] = 2
                        q.append((nx, ny))
                
        # Traverse all 4 directions
        if c % 7 == 0:
            nodes_in_current_layer = len(m)
            for _ in range(nodes_in_current_layer):
                a, b = m.popleft()
                for dx, dy in dir:
                    nx = a + dx
                    ny = b + dy

                    # Check boundary conditions and color match
                    if 0 <= nx < len(img) and 0 <= ny < len(img[0]) and img[nx][ny] == oldColor:
                        img[nx][ny] = 1
                        m.append((nx, ny))
        c += 1
    return img


# if __name__ == "__main__":
#     # Create a 20x20 2D array of 0s
#     img = [[0 for _ in range(20)] for _ in range(20)]

    
#     sr, sc = 10, 10
#     sm, sg = 10, 11
#     G = 2
#     M = 1
    
#     result = floodFill(img, sr, sc, sm, sg, G, M)
    
#     for row in result:
#         print(*row)

X_G = 0
Y_G = 0
X_M = 1
Y_M = 1

# rows, cols = 20, 20
# array_2d = [[0 for _ in range(cols)] for _ in range(rows)]
    

# array_2d[X_G - 10, Y_G - 10] = 1
# array_2d[X_M - 10, Y_M - 10] = -1



def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()
