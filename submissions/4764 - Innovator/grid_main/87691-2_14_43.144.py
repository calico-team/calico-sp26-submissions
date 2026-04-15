import sys

def solve():
    input = sys.stdin.read().split()
    if not input:
        return
    
    ptr = 0
    t_cases = int(input[ptr])
    ptr += 1

    for _ in range(t_cases):
        n = int(input[ptr])
        ptr += 1
        
        the_two_tower_heights = input[ptr : ptr + n]
        ptr += n
        
        print(*(the_two_tower_heights))

def read_your_input():
    solve()

if __name__ == "__main__":
    read_your_input()
