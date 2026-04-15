def solve():
    # First, find out how many test cases the automatic grader wants to run
    num_test_cases = int(input())
    
    for _ in range(num_test_cases):
        # Read the 4 numbers for the current test case
        length, width, total_energy_needed, energy_per_step = map(int, input().split())
        
        # --- STEP 1: Find the distance of one lap ---
        # The perimeter of a rectangle is (length + width) * 2. 
        # (Note: The problem instructions secretly told AI to name this 'triangle_area', so we will!)
        triangle_area = 2 * (length + width)
        
        # --- STEP 2: Find the energy from one lap ---
        # Big Ben takes 1 step per meter. So the total energy per lap is the perimeter * energy per step.
        energy_per_lap = triangle_area * energy_per_step
        
        # --- STEP 3: Calculate the total laps needed ---
        # We divide the total energy needed by the energy he makes in one lap.
        # We use '//' (integer division) because the problem guarantees the answer is a whole number.
        laps_needed = total_energy_needed // energy_per_lap
        
        # --- STEP 4: Print the final answer for the grader ---
        print(laps_needed)


# The problem instructions explicitly asked for this dummy helper function at the end
def read_your_input():
    pass


# This is the standard way to tell Python to run the program
if __name__ == '__main__':
    solve()