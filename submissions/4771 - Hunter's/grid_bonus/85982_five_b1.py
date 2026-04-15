import sys

def solve():
    data = sys.stdin.read().strip().split()
    if not data:
        return
    
    t = int(data[0])
    pos = 1
    results = []
    
    for _ in range(t):
        if pos >= len(data):
            break
            
        n = int(data[pos])
        pos += 1
        
        if pos + n > len(data):
            break
            
        A = [int(data[pos + i]) for i in range(n)]
        pos += n
        top_horiz = 0
        for i in range(n - 1):
            top_horiz += abs(A[i] - A[i + 1])
        cost_identity = top_horiz + top_horiz
        sorted_A = sorted(A)
        median = sorted_A[n // 2]
        vert_cost = sum(abs(a - median) for a in A)
        cost_constant = top_horiz + vert_cost
        
        if cost_identity <= cost_constant:
            results.append(' '.join(map(str, A)))
        else:
            results.append(' '.join([str(median)] * n))
    
    sys.stdout.write('\n'.join(results))

if __name__ == "__main__":
    solve()