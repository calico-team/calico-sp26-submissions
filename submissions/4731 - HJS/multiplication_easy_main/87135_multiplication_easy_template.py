import math
def solve(N, M, D, constraints):
    # log(ai) + log(aj) = log(Vi)
    # This is a system of linear equations. A simple iterative approach 
    # (like 50 rounds of averaging) will converge on a very good solution.
    log_a = [math.log(1000)] * N # Start with a neutral guess
    for _ in range(50):
        sums = [0.0] * N
        counts = [0] * N
        for r, c, v, w in constraints:
            target = math.log(v)
            sums[r] += (target - log_a[c])
            sums[c] += (target - log_a[r])
            counts[r] += 1
            counts[c] += 1
        for i in range(N):
            if counts[i] > 0:
                log_a[i] = sums[i] / counts[i]
                
    better_than_me = [int(math.exp(x)) for x in log_a]
    # ... then use the same discard logic for the D worst penalties
    return better_than_me