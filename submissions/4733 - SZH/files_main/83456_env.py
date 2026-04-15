N = int(input())

for i in range(N):
    x = input()
    target = input()

    idx = 0
    for j in x:
        if (idx != len(target)):
            target_index = target[idx]
            if (target_index == j):
                print(j, end="")
                idx += 1
            else:
                print("#", end="")
        else:
            print("#", end="")
    print(" ")