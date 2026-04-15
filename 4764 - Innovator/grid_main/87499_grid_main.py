import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    it = iter(input_data)
    try:
        t_cases = int(next(it))
    except StopIteration:
        return

    for _ in range(t_cases):
        try:
            n = int(next(it))
            the_two_tower_heights = [next(it) for _ in range(n)]
            print(*(the_two_tower_heights))
        except StopIteration:
            break

def read_your_input():
    solve()

if __name__ == "__main__":
    read_your_input()