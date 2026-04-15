def solve(N: int, S1: list[str], S2: list[str]) -> tuple[int, int]:
    """
    Return the maximal and minimal volume of the shape (in that order)
    
    N: max dimensions of shape
    S1: projection (shadow) in X-Z plane (S1[z][x])
    S2: projection (shadow) in Y-Z plane (S2[z][y])
    """
    max_vol = 0
    min_vol = 0

    # We iterate level by level (along the Z-axis)
    # The projections provide constraints for each horizontal slice at height z
    for z in range(N):
        # Count how many cubes are in the projections at this height
        # row_shadow (X-Z) tells us which x-coordinates are occupied
        # col_shadow (Y-Z) tells us which y-coordinates are occupied
        count_x = S1[z].count('1')
        count_y = S2[z].count('1')

        # If one projection has a shadow at height z but the other doesn't,
        # it's an impossible shape based on the problem constraints.
        if (count_x > 0 and count_y == 0) or (count_x == 0 and count_y > 0):
            # This case typically shouldn't happen with valid input shadows
            continue

        # Maximal Volume:
        # For a given Z, a cell (x, y) can be filled if S1[z][x] == '1' AND S2[z][y] == '1'.
        # This forms a bounding box/rectangles of area = count_x * count_y.
        max_vol += count_x * count_y

        # Minimal Volume:
        # To satisfy both projections with the fewest blocks, we use the property:
        # min_blocks = max(count_x, count_y)
        # This is because every '1' in S1 needs at least one block in its row,
        # and every '1' in S2 needs at least one block in its column.
        min_vol += max(count_x, count_y)

    return max_vol, min_vol


def main():
    import sys
    input = sys.stdin.read().split()
    if not input:
        return
    
    idx = 0
    T = int(input[idx])
    idx += 1
    for _ in range(T):
        N = int(input[idx])
        idx += 1
        S1 = input[idx : idx + N]
        idx += N
        S2 = input[idx : idx + N]
        idx += N
        print(*solve(N, S1, S2))


if __name__ == '__main__':
    main()