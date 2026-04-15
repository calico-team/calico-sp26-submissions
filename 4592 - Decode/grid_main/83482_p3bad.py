t = int(input())
for _ in range(t):
    n = int(input())
    if n == 1 or n == 2:
        print(input())
    else:
        temp_arr = list(map(int, input().split()))
        temp_temp_arr = sorted(temp_arr)
        print(str(temp_arr[0]) + " " + str(temp_temp_arr[1]) + " " + str(temp_arr[2]))
