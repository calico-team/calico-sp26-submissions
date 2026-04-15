def main():
    import sys
    input = sys.stdin.read().split()
    idx = 0
    T = int(input[idx])
    idx += 1
    dylan_power = 0
    for _ in range(T):
        N = int(input[idx])
        P = int(input[idx+1])
        R = int(input[idx+2])
        K = int(input[idx+3])
        idx += 4
        E = list(map(int, input[idx:idx+N]))
        idx += N
        power = P
        cnt = 0
        win = True
        for e in E:
            power -= e
            if power < 0:
                win = False
                break
            cnt += 1
            if cnt % K == 0:
                power += R
        print("nah i'd win" if win else "nah i'd lose")
        
def read_your_input():
    import sys
    return sys.stdin.read()
    
if __name__ == "__main__":
    main()
        
