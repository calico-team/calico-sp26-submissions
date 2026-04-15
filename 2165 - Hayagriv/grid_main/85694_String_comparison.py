import sys
from collections import deque
from collections import Counter
#input = sys.stdin.readline

def solve():
    temp_index = 0
    number_of_towers = input()
    num_of_towers_list = number_of_towers.split(" ")
    '''for item in num_of_towers_list:
        num_of_towers_list[temp_index] = int(num_of_towers_list[temp_index])
        temp_index += 1'''
    print(" ".join(num_of_towers_list))









test_cases = input().strip()
test_cases = int(test_cases)
for i in range(0,test_cases):
    solve()