import sys
from collections import deque
from collections import Counter
#input = sys.stdin.readline

def solve():
    string_b_deque_index = 0
    string_a_deque_index = 0
    string_a = input()
    string_a_deque = deque([])
    for char in string_a:
        string_a_deque.append(char)
    string_b = input()
    string_b_deque = deque([])
    for char in string_b:
        string_b_deque.append(char)
    for item in string_a_deque:
        try:
            if item == string_b_deque[string_b_deque_index]:
                string_b_deque_index+=1
                string_a_deque_index+=1
                continue

            else:
                string_a_deque[string_a_deque_index] = "#"
                string_a_deque_index+=1
        except IndexError:
            try:
                string_a_deque[string_a_deque_index] = "#"
                string_a_deque_index+=1
            except IndexError:
                break
    final_a_string = "".join(string_a_deque)
    print(final_a_string)








test_cases = input().strip()
test_cases = int(test_cases)
for i in range(0,test_cases):
    solve()