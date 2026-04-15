import sys
from math import gcd

sys.setrecursionlimit(10**6)
read_line = sys.stdin.readline

case_total = int(read_line())
final_out = []

for _ in range(case_total):
    row_total, col_total = map(int, read_line().split())
    board = [read_line().strip() for _ in range(row_total)]
    prob_cache = {}

    def merge_frac(cur_num, cur_den, add_num, add_den):
        cur_num = cur_num * add_den + add_num * cur_den
        cur_den = cur_den * add_den
        shrink = gcd(cur_num, cur_den)
        return cur_num // shrink, cur_den // shrink

    def solve_prob(row_pos, col_pos):
        cache_key = (row_pos, col_pos)
        old_val = prob_cache.get(cache_key)
        if old_val is not None:
            return old_val

        tile = board[row_pos][col_pos]

        if tile == "X":
            prob_cache[cache_key] = (0, 1)
            return 0, 1

        if tile == "^":
            next_row = row_pos - 1
            if next_row < 0:
                prob_cache[cache_key] = (1, 1)
                return 1, 1
            got_num, got_den = solve_prob(next_row, col_pos)
            prob_cache[cache_key] = (got_num, got_den)
            return got_num, got_den

        if tile == "v":
            next_row = row_pos + 1
            if next_row >= row_total:
                prob_cache[cache_key] = (1, 1)
                return 1, 1
            got_num, got_den = solve_prob(next_row, col_pos)
            prob_cache[cache_key] = (got_num, got_den)
            return got_num, got_den

        if tile == "<":
            next_col = col_pos - 1
            if next_col < 0:
                prob_cache[cache_key] = (1, 1)
                return 1, 1
            got_num, got_den = solve_prob(row_pos, next_col)
            prob_cache[cache_key] = (got_num, got_den)
            return got_num, got_den

        if tile == ">":
            next_col = col_pos + 1
            if next_col >= col_total:
                prob_cache[cache_key] = (1, 1)
                return 1, 1
            got_num, got_den = solve_prob(row_pos, next_col)
            prob_cache[cache_key] = (got_num, got_den)
            return got_num, got_den

        next_spots = []

        if row_pos > 0:
            up_tile = board[row_pos - 1][col_pos]
            if up_tile == "X" or up_tile == "^" or up_tile == "<" or up_tile == ">":
                next_spots.append((row_pos - 1, col_pos))

        if row_pos + 1 < row_total:
            down_tile = board[row_pos + 1][col_pos]
            if down_tile == "X" or down_tile == "v" or down_tile == "<" or down_tile == ">":
                next_spots.append((row_pos + 1, col_pos))

        if col_pos > 0:
            left_tile = board[row_pos][col_pos - 1]
            if left_tile == "X" or left_tile == "^" or left_tile == "v" or left_tile == "<":
                next_spots.append((row_pos, col_pos - 1))

        if col_pos + 1 < col_total:
            right_tile = board[row_pos][col_pos + 1]
            if right_tile == "X" or right_tile == "^" or right_tile == "v" or right_tile == ">":
                next_spots.append((row_pos, col_pos + 1))

        ways_cnt = len(next_spots)
        run_num = 0
        run_den = 1

        take_idx = 0
        while take_idx < ways_cnt:
            go_row, go_col = next_spots[take_idx]
            got_num, got_den = solve_prob(go_row, go_col)
            run_num, run_den = merge_frac(run_num, run_den, got_num, got_den)
            take_idx += 1

        run_den *= ways_cnt
        trim = gcd(run_num, run_den)
        run_num //= trim
        run_den //= trim

        prob_cache[cache_key] = (run_num, run_den)
        return run_num, run_den

    ans_num, ans_den = solve_prob(0, 0)
    trim = gcd(ans_num, ans_den)
    final_out.append(f"{ans_num // trim} {ans_den // trim}")

sys.stdout.write("\n".join(final_out))