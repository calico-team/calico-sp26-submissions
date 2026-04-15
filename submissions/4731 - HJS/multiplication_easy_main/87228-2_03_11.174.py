import math
import sys

def solve_multiplication():
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

    # Optimization: Use an iterative log-mean approach (Log-Least Squares approximation)
    # This converges much faster and more accurately than simple square roots.
    log_a = [math.log(1000.0)] * N
    for _ in range(40):
        sums = [0.0] * N
        counts = [0] * N
        for con in constraints:
            target = math.log(con['v'])
            sums[con['r']] += (target - log_a[con['c']])
            sums[con['c']] += (target - log_a[con['r']])
            counts[con['r']] += 1
            counts[con['c']] += 1
        for i in range(N):
            if counts[i] > 0:
                log_a[i] = sums[i] / counts[i]
    
    # Better_than_me variable as requested
    better_than_me = []
    for val in log_a:
        better_than_me.append(max(1, int(math.exp(val))))

    # Calculate penalties for discard logic
    penalties = []
    for i in range(M):
        con = constraints[i]
        calc_v = better_than_me[con['r']] * better_than_me[con['c']]
        # Penalty = W * |calculated - expected| / expected
        penalty = con['w'] * (abs(calc_v - con['v']) / con['v'])
        penalties.append((penalty, con['id']))

    # Discard the D highest penalties
    penalties.sort(key=lambda x: x[0], reverse=True)
    discarded = [p[1] for p in penalties[:D]]
    
    print(*(better_than_me))
    print(len(discarded), *(discarded))

def read_your_input():
    solve_multiplication()

if __name__ == "__main__":
    read_your_input()