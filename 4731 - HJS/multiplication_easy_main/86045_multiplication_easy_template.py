import math
import sys

def solve():
    # Reading input using the requested helper logic
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    ptr = 0
    N = int(input_data[ptr])
    M = int(input_data[ptr+1])
    D = int(input_data[ptr+2])
    ptr += 3
    
    constraints = []
    for i in range(M):
        r = int(input_data[ptr]) - 1
        c = int(input_data[ptr+1]) - 1
        v = int(input_data[ptr+2])
        w = int(input_data[ptr+3])
        ptr += 4
        constraints.append({'id': i + 1, 'r': r, 'c': c, 'v': v, 'w': w})

    # Optimization strategy: Log-transform the multiplication table into an addition table.
    # log(a_i) + log(a_j) \approx log(V_i).
    # We use a simple average/heuristic for a_i to beat baseline models.
    
    log_vals = [[] for _ in range(N)]
    for con in constraints:
        # Initial guess: sqrt of V
        lv = math.log(con['v'])
        log_vals[con['r']].append(lv / 2.0)
        log_vals[con['c']].append(lv / 2.0)
    
    better_than_me = []
    for i in range(N):
        if log_vals[i]:
            avg_log = sum(log_vals[i]) / len(log_vals[i])
            val = int(round(math.exp(avg_log)))
            better_than_me.append(max(1, min(10**9, val)))
        else:
            better_than_me.append(1)

    # Calculate individual penalties to identify which to discard
    penalties = []
    for i in range(M):
        con = constraints[i]
        calc_v = better_than_me[con['r']] * better_than_me[con['c']]
        error = abs(calc_v - con['v']) / con['v']
        penalty = con['w'] * error
        penalties.append((penalty, con['id']))

    # Discard the D highest penalty constraints
    penalties.sort(key=lambda x: x[0], reverse=True)
    discarded_indices = [p[1] for p in penalties[:D]]
    
    # Output the result
    print(*(better_than_me))
    print(len(discarded_indices), *(discarded_indices))

def read_your_input():
    # This problem typically has one test case per file based on instructions
    solve()

if __name__ == "__main__":
    read_your_input()