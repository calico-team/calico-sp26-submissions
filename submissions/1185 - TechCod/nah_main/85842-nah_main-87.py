def win(n, p, r, k, energy):
    defeated=0
    for e in energy:
        p-= e
        if p<0: return "nah i'd lose"
        defeated +=1
        if defeated %k== 0:
            p+=r
    return "nah i'd win"
def main():
    T= int(input().strip())
    for _ in range(T):
        N, P,R, K=map(int, input().split())
        E=list(map(int, input().split()))
        print(win(N,P,R,K,E))

if __name__ =="__main__":
    main()