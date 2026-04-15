T = int(input())
for i in range(T):
        L, W, E, R = input().split()
        L, W, E, R = int(L), int(W), int(E), int(R)
        P = (2*L)+(2*W)
        laps = int(E/(P*R))
        print(laps) 
