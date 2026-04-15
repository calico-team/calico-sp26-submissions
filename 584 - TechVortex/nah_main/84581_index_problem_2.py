def power_calcultor_gojo(P,R,K,E):
    winner = False
    if P >= sum(E):
        winner = True
        return winner 
    for i in range(len(E)):
        if P >= E[i]:
            P-=E[i]
        else:
            if i < K:
                return winner
            else:
                P+=R
                if P < E[i]:
                    return winner
                else:
                    P-=E[i]
    if P>=0:
        winner = True
    return winner

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