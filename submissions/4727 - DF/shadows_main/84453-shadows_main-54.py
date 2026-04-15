import sys

def solve(N: int, S1: list[str], S2: list[str]) -> tuple[int, int]:
    
    max_vol = 0
    min_vol = 0
    
    for z in range(N):
        count1 = S1[z].count('#')
        count2 = S2[z].count('#')
        
        if count1 == 0 and count2 == 0:
            continue
            
        max_vol += count1 * count2
        
        min_vol += max(count1, count2)
        
    return max_vol, min_vol


def main():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    it = iter(input_data)
    try:
        T_str = next(it)
        T = int(T_str)
        for _ in range(T):
            N = int(next(it))
            S1 = [next(it) for _ in range(N)]
            S2 = [next(it) for _ in range(N)]
            res = solve(N, S1, S2)
            print(f"{res[0]} {res[1]}")
    except StopIteration:
        pass


if __name__ == '__main__':
    main()
