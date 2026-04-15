import sys

def solve():
    # Reading all input at once to handle different line formats easily
    # This reads every number and puts it in a single list
    try:
        input_data = sys.stdin.read().split()
    except EOFError:
        return
        
    if not input_data:
        return
    
    # Pointer to track our position in the input list
    pointer = 0
    
    # First number is the number of test cases (T)
    t = int(input_data[pointer])
    pointer += 1
    
    for _ in range(t):
        # Reading N, P, R, and K for each test case
        n = int(input_data[pointer])      # Number of curses [cite: 25]
        p = int(input_data[pointer + 1])  # Initial power level [cite: 26]
        r = int(input_data[pointer + 2])  # Restoration amount [cite: 27]
        k = int(input_data[pointer + 3])  # Curses needed for heal [cite: 28]
        pointer += 4
        
        # Power levels of all N curses [cite: 11]
        e = []
        for i in range(n):
            e.append(int(input_data[pointer]))
            pointer += 1
            
        defeated_count = 0
        is_defeated = False
        
        # Go through each curse one by one 
        for curse_power in e:
            # Gojo fights the curse and loses power 
            p -= curse_power
            
            # If power drops below 0, Gojo loses 
            if p < 0:
                is_defeated = True
                break
            
            # Successfully defeated one curse
            defeated_count += 1
            
            # After every K curses, Gojo can heal 
            if defeated_count == k:
                p += r
                defeated_count = 0 # Reset counter for next cycle
        
        # Final output based on whether Gojo survived [cite: 17]
        if not is_defeated:
            print("nah i'd win")
        else:
            print("nah i'd lose")

if __name__ == "__main__":
    solve()