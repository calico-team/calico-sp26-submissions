def solve(L, W, E, R):
    """
    Return the number of lps needed to charge the car (rounded up)

    L: Length of car
    W: Width of car
    E: Amount of electricity to generate
    R: Electricity generated per unit distance
    """
    
    pmr = 2 * (L + W)
    

    elp = pmr * R
    
    lps = E // elp
    
    return lps

def main():
    
    ts = input().strip()
    if not ts:
        return
    T = int(ts)
    
    for _ in range(T):
        
        temp = input().split()
        if not temp:
            continue
        L = int(temp[0])
        W = int(temp[1])
        E = int(temp[2])
        R = int(temp[3])

        print(solve(L, W, E, R))

if __name__ == "__main__":
    main()