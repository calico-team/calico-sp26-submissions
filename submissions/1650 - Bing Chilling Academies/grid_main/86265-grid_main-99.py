def solve3():
    nums = list(map(int, input().split()))

    middle = sorted(nums)[1]
    print(f"{nums[0]} {middle} {nums[2]}")


t = int(input())
for _ in range(t):
    n = int(input())

    if n == 1:
        print(input())
    elif n == 2:
        print(input())
    elif n == 3:
        solve3()
    else:
        print("i lose the game")
