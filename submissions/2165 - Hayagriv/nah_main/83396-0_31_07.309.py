import sys
from collections import deque
from collections import Counter
#input = sys.stdin.readline

def solve():
    amount_reverse_counter = 0
    gojo_stats = input()
    gojo_stats_split = gojo_stats.split(" ")
    Num_of_curses = int(gojo_stats_split[0])
    Power_level = int(gojo_stats_split[1])
    Reversed_Cursed_Techniques = int(gojo_stats_split[2])
    Amount_to_Reversed = int(gojo_stats_split[3])
    cursed_spirits = input()
    cursed_spirits_split = cursed_spirits.split(" ")
    for i in cursed_spirits_split:
        Power_level-= int(i)
        amount_reverse_counter+=1
        if amount_reverse_counter >= Amount_to_Reversed:
            Power_level += Reversed_Cursed_Techniques
        if Power_level < 0:
            print("nah i'd lose")
            return

    print("nah i'd win")









test_cases = input().strip()
test_cases = int(test_cases)
for i in range(0,test_cases):
    solve()