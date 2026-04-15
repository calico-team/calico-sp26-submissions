def solve(N: int, P: int, R: int, K: int, E: list[int]) -> str:
    """
    Output whether Gojo will win the fight. [cite: 72]

    N: Number of curses [cite: 80]
    P: Gojo's starting power [cite: 81]
    R: Amount of power Gojo can restore with Reverse Cursed Technique [cite: 82]
    K: The cooldown of Reverse Cursed Technique [cite: 83]
    E: List of power levels of curses [cite: 84]
    """
    d_c = 0
    cp = P

    for c_r in E:
        # Gojo faces the curse and his power level is depleted 
        cp -= c_r
        
        # If power falls below 0, he is defeated 
        if cp < 0:
            return "nah i'd lose"
        
        # He has successfully defeated one more curse
        d_c += 1
        
        # Every time he defeats K curses, he can use Reverse Cursed Technique 
        if d_c % K == 0:
            cp += R
            
    return "nah i'd win"

def main() -> None:
    t_S = input().strip()
    if not t_S:
        return
    T = int(t_S)
    for _ in range(T):
        l1 = input().split()
        if not l1:
            continue
        N, P, R, K = map(int, l1)
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))

if __name__ == "__main__":
    main()