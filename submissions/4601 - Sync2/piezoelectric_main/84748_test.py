T = int(input())

for _ in range(T):
    L, W, E, R = map(int, input().split())

   
    p = 2 * (L + W)

   
    energy_needed = p * R

   
    laps = E // energy_needed

    print(laps)