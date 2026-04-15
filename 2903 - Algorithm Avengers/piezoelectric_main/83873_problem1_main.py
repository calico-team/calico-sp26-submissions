num=int(input()) #no. of test cases
for i in range(num):
 L,W,E,R = map(int, input().split())
 P = (2*L)+(2*W)
 Lap_one=R*P
 Total_Laps=E/Lap_one
 print(f"Total Laps against input{i+1}: ", Total_Laps)