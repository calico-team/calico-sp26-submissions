import sys
from collections import deque
from collections import Counter
#input = sys.stdin.readline

def solve():
    perimeter_and_other_stuff = input()
    split_input = perimeter_and_other_stuff.split(" ")
    #print(split_input)
    Length = int(split_input[0])
    Width = int(split_input[1])
    Energy_needed = int(split_input[2])
    Rate_of_Energy = int(split_input[3])
    perimeter = (Length+Width)*2
    Energy_per_round = perimeter*Rate_of_Energy
    Rounds = Energy_needed/Energy_per_round
    print(int(Rounds))






test_cases = input().strip()
test_cases = int(test_cases)
for i in range(0,test_cases):
    solve()