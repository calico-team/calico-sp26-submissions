def laps_possible(l, w, e, r):
    peri = 2*(l+w)
    cost=peri*r
    return e//cost
def main():
    try: T= int(input().strip())
    except:
        return
    for _ in range(T): 
        values =input().strip().split()
        if not values: continue
        L, W, E, R=map(int, values)
        print(laps_possible(L, W, E, R))

if __name__ =="__main__":
    main()