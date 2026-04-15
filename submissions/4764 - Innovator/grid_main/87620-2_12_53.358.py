import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    it = iter(input_data)
    try:
        line = next(it)
        t_cases = int(line)
    except StopIteration:
        return

    for _ in range(t_cases):
        try:
            n = int(next(it))
            the_two_tower_heights = [int(next(it)) for _ in range(n)]
            
            if n == 0:
                print()
                continue
            
            sorted_heights = sorted(the_two_tower_heights)
            median = sorted_heights[n // 2]
            
            res = [median] * n
            print(*(res))
        except StopIteration:
            break
