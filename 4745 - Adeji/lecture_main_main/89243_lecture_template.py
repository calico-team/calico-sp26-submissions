def man_distance(A, B):
    return abs(A[0] - B[0]) + abs(A[1] - B[1])

def solve(N, M, K, GRID):
    """
    N: number of rows in the lecture hall
    M: number of columns in the lecture hall
    K: number of friends who need seats
    GRID: list of N strings of length M; '#' is a blocked seat, '-' is an empty seat

    Return a list of K (row, col) tuples for the chosen seats.
    """
    open_seats = []
    for i, row in enumerate(GRID):
        for j, item in enumerate(row):
            if item == '-':
                open_seats.append([i, j])
    man_distance_sets = []
    man_dist_sets_vals = {}
    for i, seat in enumerate(open_seats):
        man_dists = {}
        for j, seat2 in enumerate(open_seats):
            dist = man_distance(seat, seat2)
            if len(man_dists) < K:
                man_dists[j] = dist

            else:
                for t in man_dists.keys():
                    if man_dists[t] > dist:
                        man_dists.pop(t)
                        man_dists[j] = dist
                        break
        man_distance_sets.append(man_dists)
    for j,i in enumerate(man_distance_sets):
        man_dist_sets_vals[sum(i.values())] = j
    min_dist = min(man_dist_sets_vals.keys())
    man_dist_i = man_dist_sets_vals[min_dist]
    # print(man_dist_i)
    # print(man_distance_sets)

    a = man_distance_sets[man_dist_i]
    b = list(a.keys())


    return [open_seats[b[k]] for k in range(K)]


def main():
    T = int(input())
    for _ in range(T):
        N, M, K = map(int, input().split())
        GRID = []
        for _ in range(N):
            GRID.append(input().strip())
        result = solve(N, M, K, GRID)
        for r, c in result:
            print(f"{r} {c}")


if __name__ == '__main__':
    main()
