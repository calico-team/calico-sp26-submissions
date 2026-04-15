
def power_calcultor_gojo(P,R,K,E):
    deafeated = 0 
    for i in range(len(E)):
        P -= E[i]
        if P <0: 
            return False
        deafeated += 1 
        if deafeated % K == 0:
            P+=R
    return True 
    
def main():
    import sys
    import os 
    if sys.stdin.isatty() and os.path.exists('1.in'):
        sys.stdin = open('1.in', 'r')

    input_data = sys.stdin.read().split()
    if not input_data:
        return
    iterator = iter(input_data)
    try :
        T = int(next(iterator))
        for _ in range(T):
            N= int(next(iterator))
            P= int(next(iterator))
            R= int(next(iterator))
            K= int(next(iterator))

            E = []
            for _ in range(N):
                E.append(int(next(iterator)))
            if power_calcultor_gojo(P,R,K,E):
                print("nah i'd win")
            else:
                print("nah i'd lose")
    except StopIteration:
        pass
if __name__ == "__main__":
    main()