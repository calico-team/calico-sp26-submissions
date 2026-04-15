def main():
    
    T = int(input())
    
    for _ in range(T):
        
        L, W, E, R = map(int, input().split())
        
        perimeter = 2 * (L + W)
        
        power_per_lap = perimeter * R
        
        laps = E // power_per_lap
        
        print(laps)
if __name__ == "__main__":
    main()
