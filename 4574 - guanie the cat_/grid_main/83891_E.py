for _ in range(int(input())):
    n = int(input())
    nums = [int(i) for i in input().split()]
    if n == 1:
        print(nums[0])
    elif n == 2:
        ans = [(nums[0]+nums[1])//2,(nums[0]+nums[1])//2]
        print(*ans)
    elif n == 3:
        mid = sorted(nums)[1]
        ans = [(nums[0]+mid)//2,mid,(mid+nums[2])//2]
        print(*ans)