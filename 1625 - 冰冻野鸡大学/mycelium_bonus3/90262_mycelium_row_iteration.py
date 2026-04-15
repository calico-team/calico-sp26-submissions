"""
O(D) closed-form row-iteration solution.

Uses the same closed-form xmin/xmax boundary formulas as the O(log D)
floor-sum solution, but iterates over each row yr and sums widths directly
instead of using the Hermite/Stern-Brocot floor-sum identity.

This simulates what a math-oriented contestant might write after deriving
the per-row formulas but without the final floor-sum optimization.
"""


GRASS_DELAY = 2
MYCELIUM_DELAY = 7


def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    """
    Return the total number of tiles mycelium will ever occupy.

    X_G: x-coordinate of grass starting position
    Y_G: y-coordinate of grass starting position
    X_M: x-coordinate of mycelium starting position
    Y_M: y-coordinate of mycelium starting position
    """
    dx = abs(X_M - X_G)
    dy = abs(Y_M - Y_G)
    p = max(dx, dy)
    q = min(dx, dy)
    D = p + q          # Manhattan distance
    A = p - q          # Asymmetry parameter

    if D == 0:
        return 1

    # Vertical extent of the mycelium region.
    y_top = (2 * D - 1) // 5
    y_bot_s1 = min(q, (2 * D - 1) // 9) if D > 0 else 0
    y_bot_s2 = (2 * A - 1) // 5 if A > 0 else 0
    y_bot = max(y_bot_s1, y_bot_s2)

    # Constants for the bypass formulas.
    C_top = 2 * D + 4 * (y_top + 1) - 1
    C_bot = 2 * A + 4 * (y_bot + 1) - 1
    C_bot_eff = max(C_bot, 2 * D - 1)
    R_peak = C_bot_eff // 5
    C_mid = C_bot_eff + 4 * (R_peak + 1)

    total = 0

    for yr in range(-y_bot, y_top + 1):
        # --- xmin ---
        if yr >= 0:
            xmin = -((2 * D - 5 * yr - 1) // 9)
        elif yr >= -q:
            xmin = -((2 * D + 9 * yr - 1) // 9)
        else:
            xmin = -((2 * A + 5 * yr - 1) // 9)

        # --- xmax ---
        if yr >= 0:
            top_val = (C_top - 9 * yr) // 5
            mid_val = (C_mid - 5 * yr) // 9
            xmax = min(top_val, mid_val)
        else:
            top_val = (C_top + 5 * yr) // 5
            bot_val = (C_bot_eff + 9 * yr) // 5
            xmax = min(top_val, bot_val)

        total += xmax - xmin + 1

    return total


def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()
