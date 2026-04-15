import sys
import math

def solve():
    raw_data = sys.stdin.read().split()
    if not raw_data:
        return
    
    ptr = 0
    n = int(raw_data[ptr]); ptr += 1
    m = int(raw_data[ptr]); ptr += 1
    d_limit = int(raw_data[ptr]); ptr += 1
    
    adj = [[] for _ in range(n + 1)]
    constraints = []
    
    for i in range(1, m + 1):
        u = int(raw_data[ptr]); ptr += 1
        v = int(raw_data[ptr]); ptr += 1
        val = int(raw_data[ptr]); ptr += 1
        w = int(raw_data[ptr]); ptr += 1
        constraints.append((u, v, val, w, i))
        l_val = math.log(val)
        adj[u].append((v, l_val, w))
        adj[v].append((u, l_val, w))

    log_a = [10.0] * (n + 1)

    iterations = 30
    for _ in range(iterations):
        for i in range(1, n + 1):
            if not adj[i]:
                continue
            
            candidates = []
            total_w = 0
            for neighbor, target_log_prod, weight in adj[i]:

                candidates.append((target_log_prod - log_a[neighbor], weight))
                total_w += weight
            
            candidates.sort()
            
            current_w = 0
            median_log = candidates[0][0]
            for val, weight in candidates:
                current_w += weight
                if current_w >= total_w / 2:
                    median_log = val
                    break
            log_a[i] = median_log

    a_results = []
    for i in range(1, n + 1):
        val = int(round(math.exp(log_a[i])))
        if val < 1: val = 1
        elif val > 1000000000: val = 1000000000
        a_results.append(val)
    
    penalties = []
    for u, v, val, w, idx in constraints:

        actual_val = a_results[u-1] * a_results[v-1]
        penalty = w * (abs(actual_val - val) / val)
        penalties.append((penalty, idx))

    penalties.sort(key=lambda x: x[0], reverse=True)
    
    num_discarded = min(d_limit, m)
    discarded_ids = [penalties[i][1] for i in range(num_discarded)]

    print(*(a_results))
    print(num_discarded, *(discarded_ids))

if __name__ == "__main__":
    solve()
