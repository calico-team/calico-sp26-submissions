n = int(input())
nums = list(map(int, input().split()))
evens = [x for x in nums if x % 2 == 0]
odds = [x for x in nums if x % 2 != 0]
print(len(evens)) # count of evens
print(sum(odds)) # sum of odds