import sys
import random
import math

input =sys.stdin.read
data =input().split()

idx = 0
N =int(data[idx])
M =int(data[idx + 1])
D =int(data[idx + 2])
idx += 3

constraints = []
for i in range(M):
    R = int(data[idx]) - 1
    C = int(data[idx + 1]) - 1
    V = int(data[idx + 2])
    W = int(data[idx + 3])
    constraints.append((R, C, V, W))
    idx += 4

candidates = set()
for _, _, v, _ in constraints:
    if v > 0:
        s = int(math.sqrt(v))
        for d in range(-10, 11):
            if s + d > 0:
                candidates.add(s + d)
            if s * 2 + d > 0:
                candidates.add(s * 2 + d)

cands =sorted(list(candidates))[:100]
if not cands:
    cands= ist(range(1, 21))

best_penalty= float('inf')
best_a =None
best_discarded= []

for trial in range(300):
    a = [random.choice(cands) for _ in range(N)]
    
    for it in range(30):
        for i in range(N):
            best_val = a[i]
            best_local = float('inf')
            for val in cands:
                a[i] = val
                errors =[]
                for r, c, v, w in constraints:
                    prod =a[r] * a[c]
                    rel= abs(prod - v) / v if v != 0 else abs(prod)
                    errors.append(rel * w)
                total = sum(errors)
                if total < best_local:
                    best_local = total
                    best_val = val
            a[i] = best_val
    
    errors=[]
    for k, (r, c, v, w) in enumerate(constraints):
        prod = a[r] * a[c]
        rel = abs(prod - v) / v if v != 0 else abs(prod)
        errors.append((rel * w, k))
    
    errors.sort(reverse=True)
    discarded_set = set()
    d = min(D, len(errors))
    for i in range(d):
        discarded_set.add(errors[i][1] + 1)
    
    current_penalty=sum(e[0] for e in errors[d:])
    
    if current_penalty < best_penalty:
        best_penalty = current_penalty
        best_a = a[:]
        best_discarded = sorted(list(discarded_set))

if not best_discarded and D > 0:
    best_discarded = []

print(' '.join(map(str, sorted(best_a))))
print(len(best_discarded), end='')
for s in best_discarded:
    print(' ', s, end='', sep='')
print()