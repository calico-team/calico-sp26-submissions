def solve(X_G, Y_G, X_M, Y_M):
    # Manhattan distance between sources
    D = abs(X_G - X_M) + abs(Y_G - Y_M)

    # Maximum radius where mycelium can possibly win
    max_dist = (2 * D) // 5 + 5   # safe margin

    count = 0

    # Iterate only around mycelium (diamond region)
    for dx in range(-max_dist, max_dist + 1):
        for dy in range(-max_dist, max_dist + 1):
            if abs(dx) + abs(dy) > max_dist:
                continue

            x = X_M + dx
            y = Y_M + dy

            dist_myc = abs(dx) + abs(dy)
            dist_grass = abs(x - X_G) + abs(y - Y_G)

            if 7 * dist_myc < 2 * dist_grass:
                count += 1

    return count


def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == "__main__":
    main()