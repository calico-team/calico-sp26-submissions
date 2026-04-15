t = int(input())
for _ in range(t):
    n = int(input())
    if n == 1 or n == 2:
        print(input())
    elif n == 3:
        temp_arr = list(map(int, input().split()))
        temp_temp_arr = sorted(temp_arr)
        print(str(temp_arr[0]) + " " + str(temp_temp_arr[1]) + " " + str(temp_arr[2]))
    else:
        arr = list(map(int, input().split()))
        peaks = {0: 0, (n - 1): 0}
        for i in range(1, n - 1):
            if arr[i] > arr[i - 1] and arr[i] > arr[i + 1]:
                peaks[i] = 1
            elif arr[i] < arr[i - 1] and arr[i] < arr[i + 1]:
                peaks[i] = -1
            else:
                peaks[i] = 0
        current_num = arr[0]
        print(current_num, end="")
        for i in range(1, n):
            if peaks[i] == 1:
                current_num = max(current_num, arr[i + 1])
            elif peaks[i] == -1:
                current_num = min(current_num, arr[i + 1])
            else:
                current_num = arr[i]
            print(" " + str(current_num), end="")
        print()
