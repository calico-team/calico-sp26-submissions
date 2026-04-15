n, target = map(int, input().split())
nums = list(map(int, input().split()))
nums.sort()
left, right = 0, n - 1
found = False
while left < right:
 s = nums[left] + nums[right]
 if s == target:
 found = True
 break
 elif s < target:
 left += 1
 else:
 right -= 1
print("YES" if found else "NO")
