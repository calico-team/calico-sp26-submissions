import sys

input_data = sys.stdin.read().split()

ptr = 0
num_v = int(input_data[ptr]); ptr += 1
num_c = int(input_data[ptr]); ptr += 1
num_rem = int(input_data[ptr]); ptr += 1

graph = [[] for _ in range(num_v + 1)]
obs = []
for i in range(1, num_c + 1):
    r = int(input_data[ptr]); ptr += 1
    c = int(input_data[ptr]); ptr += 1
    v = int(input_data[ptr]); ptr += 1
    w = int(input_data[ptr]); ptr += 1
    obs.append((r, c, v, w, i))
    graph[r].append((c, v, w))
    graph[c].append((r, v, w))
    
vals = [10000] * (num_v + 1)

for _ in range(1):
    for i in range(1, num_v + 1):
        if not graph[i]: continue
        points = []
        total_w = 0.0
        for neighbor, target_v, weight_v in graph[i]:
            x = target_v / vals[neighbor]
            w_prime = (weight_v * vals[neighbor]) / target_v
            points.append((x, w_prime))
            total_w += w_prime
        
        points.sort()
        curr_w = 0.0
        for x_val, weight in points:
            curr_w += weight
            if curr_w >= total_w / 2.0:
                vals[i] = max(1, int(x_val + 0.5))
                break
                
print(*(vals[1:]))

penalties = []
for r, c, v, w, idx in obs:
    error = w * abs(vals[r] * vals[c] - v) / v
    penalties.append((error, idx))

penalties.sort(key=lambda x: x[0], reverse=True)

discarded = [str(penalties[i][1]) for i in range(min(num_rem, num_c))]
print(len(discarded), " ".join(discarded))
