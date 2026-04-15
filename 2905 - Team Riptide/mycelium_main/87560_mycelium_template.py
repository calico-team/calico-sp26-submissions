def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    """
    Return the total number of tiles mycelium will ever occupy.

    X_G: x-coordinate of grass starting position
    Y_G: y-coordinate of grass starting position
    X_M: x-coordinate of mycelium starting position
    Y_M: y-coordinate of mycelium starting position
    """
    # YOUR CODE HERE
    A = X_G - X_M
    B = Y_G - Y_M
    L = abs(A) + abs(B)

    R = (2 * L) // 5 + 2
    count = 0

    for dx in range(-R, R + 1):
        target = 2 * abs(dx - A) - 7 * abs(dx) - 1
        is_x_axis = (A == 0 and dx == 0)

        rhs1 = target - 2 * B
        if is_x_axis and B < 0:
            rhs1 += 4

        y_max = rhs1 // 5
        y_min_limit = max(0, B)
        if y_max >= y_min_limit:
            count += (y_max - y_min_limit + 1)

        rhs2 = -target - 2 * B
        if is_x_axis and B > 0:
            rhs2 -= 4

        y_min = (rhs2 + 4) // 5 if rhs2 >= 0 else rhs2 // 5
        y_max_limit = min(0, B)
        if y_min <= y_max_limit:
            count += (y_max_limit - y_min + 1)

        if B > 0:
            y_max_p3 = (target + 2 * B) // 9
            high = min(y_max_p3, B - 1)
            if high >= 1:
                count += (high - 1 + 1)
        elif B < 0:
            y_min_p3 = (2 * B - target + 8) // 9
            low = max(y_min_p3, B + 1)
            if low <= -1:
                count += (-1 - low + 1)

    return count


line = input()
if line:
    T_cases = int(line)
    for _ in range(T_cases):
        coords = list(map(int, input().split()))
        if len(coords) == 4:
            print(solve(coords[0], coords[1], coords[2], coords[3]))


def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()
