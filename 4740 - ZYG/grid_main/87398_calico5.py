
import sys
from itertools import product

data = sys.stdin.read().strip().split()
t = int(data[0])
idx = 1
out_lines = []
import sys

data = sys.stdin.read().split()
t = int(data[0])
idx = 1
out = []

for j in range(t):
    n = int(data[j]); j += 1
    A = list(map(int, data[j:j+n])); j += n
    
    if n == 1:
        out.append(str(A[0]))
        continue
    
    pairs = [(A[i], 2 if i == 0 or i == n-1 else 3) for i in range(n)]
    pairs.sort()
    
    total = 3 * n - 2
    half = total // 2
    cum = 0
    m = None
    for val, w in pairs:
        cum += w
        if cum > half:
            m = val
            break
    
    out.append(' '.join(str(m) for i in range(n)))

print('\n'.join(out))
