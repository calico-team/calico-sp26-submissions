def solve(N: int, S1: list[str], S2: list[str]) -> tuple[int, int]:
    max_vol = 0
    min_vol = 0
    
    for z in range(N):
        row1 = S1[z]
        row2 = S2[z]
        
        count1 = row1.count('#')
        count2 = row2.count('#')
        
        if (count1 == 0) != (count2 == 0):
            return 0, 0
            
        if count1 == 0:
            continue
            
        max_vol += count1 * count2
        min_vol += max(count1, count2)
        
    return max_vol, min_vol


def main():
    import sys
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    it = iter(input_data)
    T = int(next(it))
    for _ in range(T):
        N = int(next(it))
        S1 = [next(it) for _ in range(N)]
        S2 = [next(it) for _ in range(N)]
        print(*solve(N, S1, S2))


if __name__ == '__main__':
    main()
