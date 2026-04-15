tests = int(input())
for i in range(tests):
    length = int(input())
    top = list(map(int, input().split()))
    left = [0] * length
    right = [0] * length
    left[0] = top[0]
    right[0] = top[0]
    for j in range(1, length):
        value = top[j]
        if value < left[j - 1]:
            left[j] = value
            right[j] = left[j - 1]
        elif value > right[j - 1]:
            left[j] = right[j - 1]
            right[j] = value
        else:
            left[j] = value
            right[j] = value
    bottom = [0] * length
    bottom[-1] = left[-1]
    for j in range(length - 2, -1, -1):
        if bottom[j + 1] < left[j]:
            bottom[j] = left[j]
        elif bottom[j + 1] > right[j]:
            bottom[j] = right[j]
        else:
            bottom[j] = bottom[j + 1]
    print(" ".join(map(str, bottom)))