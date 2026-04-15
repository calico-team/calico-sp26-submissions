def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    """
    Return the total number of tiles mycelium will ever occupy.

    X_G: x-coordinate of grass starting position
    Y_G: y-coordinate of grass starting position
    X_M: x-coordinate of mycelium starting position
    Y_M: y-coordinate of mycelium starting position
    """
    # YOUR CODE HERE
    dx = X_G - X_M
    dy = Y_G - Y_M
    
    D = abs(dx) + abs(dy)
    R = 2 * D
    
    count = 0
    
    for x in range(-R, R + 1):
        for y in range(-R, R + 1):
            dM = abs(x) + abs(y)
            dG = abs(x - dx) + abs(y - dy)
            
            if 7 * dM < 2 * dG:
                count += 1
                
    return count


def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()
