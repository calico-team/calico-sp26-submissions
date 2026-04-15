def solve(L, W, E, R):
  
    #perimeter of Rectangle
    perim = 2 *(L +W)
    
    # how much energy one full lap gives
    energy_per_lap= perim *R
    
    #total laps needed
    laps= E // energy_per_lap
    
    return laps

def main():
    T = int(input())
    for _ in range(T):
        temp = input().split()
        L = int(temp[0])
        W = int(temp[1])
        E = int(temp[2])
        R = int(temp[3])

        print(solve(L, W, E, R))

if __name__ == "__main__":
    main()