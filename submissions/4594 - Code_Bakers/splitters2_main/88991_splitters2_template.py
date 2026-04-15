def solve(P, A, B):
    """
    Build a factory with N rows and M columns that produces the target rate.
    
    P: the target numerator of the fraction P / (2^A * 3^B)
    A: the exponent of 2 in the denominator
    B: the exponent of 3 in the denominator
    """
    # idea: build 3-row factory with splitters going left to right
    # halvings = 2-way splits (top action + right), bottom stays empty
    # thirdings = 3-way splits (top action + right + bottom action)
    # greedily collect sheds based on remaining P
    
    steps = A + B
    top_actions = []
    bottom_actions = []
    remaining_r = P

    # halving steps first
    for k in range(A):
        shed_units = (2 * (A - k - 1)) * (3 * B)
        if remaining_r >= shed_units:
            top_actions.append('^')   # collect through top edge
            remaining_r -= shed_units
        else:
            top_actions.append('X')   # destroy
        bottom_actions.append('.')    # halver is 2-way so bottom is empty

    # thirding steps next
    for k in range(B):
        shed_units = 3 ** (B - k - 1)
        collected = min(2, remaining_r // shed_units)
        remaining_r -= collected * shed_units
        if collected == 2:
            top_actions.append('^')
            bottom_actions.append('v')  # collect through bottom edge
        elif collected == 1:
            top_actions.append('^')
            bottom_actions.append('X')  # destroy one, collect one
        else:
            top_actions.append('X')
            bottom_actions.append('X')  # destroy both

    # build the actual grid
    M = 2 * steps + 2
    row0 = ['.'] * M
    row1 = ['.'] * M
    row2 = ['.'] * M

    # entry point at top left
    row0[0] = 'v'
    row1[0] = '>'

    for k in range(steps):
        col = 2 * k + 1
        row0[col] = top_actions[k]
        row1[col] = 'S'
        row2[col] = bottom_actions[k]
        row1[col + 1] = '>'

    # destroy leftover flow at the end (remaining_r is always 0 here)
    row1[2 * steps + 1] = 'X'

    return [''.join(row0), ''.join(row1), ''.join(row2)]


def main():
    T = int(input())
    for _ in range(T):
        P, A, B = map(int, input().split())
        factory = solve(P, A, B)
        N = len(factory)
        M = len(factory[0])
        print(N, M)
        for row in factory:
            print(row)


if __name__ == "__main__":
    main()