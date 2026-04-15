def solve():
    import sys
    input = sys.stdin.read().split()
    idx = 0
    T = int(input[idx])
    idx += 1
    for _ in range(T):
        L = int(input[idx])
        W = int(input[idx+1])
        E = int(input[idx+2])
        R = int(input[idx+3])
        idx += 4
        
        # 计算周长
        perimeter = 2 * (L + W)
        # 计算每圈产生的电量
        energy_per_lap = perimeter * R
        # 计算需要的圈数
        laps = E // energy_per_lap
        print(laps)

if __name__ == "__main__":
    solve()
