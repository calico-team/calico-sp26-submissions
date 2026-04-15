import sys

def main():
    # Efficiently read all input data
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    ptr = 0
    # Read the number of test cases
    t_cases = int(input_data[ptr])
    ptr += 1
    
    for _ in range(t_cases):
        # Read N (the number of columns)
        n = int(input_data[ptr])
        ptr += 1
        
        # Read the heights of the top tower (A)
        a_row = input_data[ptr : ptr + n]
        ptr += n
        
        # OPTIMAL STRATEGY: Mirror the top row.
        # This makes the vertical difference between rows 0.
        print(" ".join(a_row))

if __name__ == "__main__":
    main()
