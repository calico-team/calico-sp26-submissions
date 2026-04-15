num=int(input())
for i in range (num):
    L,W,E,R = map(int, input().split())
    P=(2*L)+(2*W)
    Lap_one=R*P 
    Total_Laps=E/Lap_one
    print(Total_Laps)
 