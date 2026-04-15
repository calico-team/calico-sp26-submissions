t = int(input())

for i in range(t):
    L, W, E, R = map(int, input().split())
    
    p = 2 * (L + W)
    energy = p * R
    laps = E // energy
    
    print(laps)