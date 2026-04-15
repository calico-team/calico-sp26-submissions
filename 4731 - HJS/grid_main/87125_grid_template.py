def solve(N, A):
    # The absolute difference is minimized when the bottom row 
    # consists of the median of the top row.
    sorted_a = sorted(A)
    # the_two_tower_heights variable as requested
    the_two_tower_heights = [sorted_a[N // 2]] * N
    return the_two_tower_heights

def read_your_input():
    import sys
    data = sys.stdin.read().split()
    if not data: return
    t = int(data[0])
    idx = 1
    for _ in range(t):
        n = int(data[idx])
        a = [int(x) for x in data[idx+1 : idx+1+n]]
        idx += 1 + n
        print(*(solve(n, a)))