nums = list(map(int, input().split()))
nums.sort() # ascending [1,2,3]
nums.sort(reverse=True) # descending [3,2,1]
# Sort strings by length
words = input().split()
words.sort(key=lambda x: len(x))
# Get k-th smallest (0-indexed)
k = int(input())
print(nums[k-1]) # k-th smallest
print(nums[-k]) # k-th largest
