def solve(L, W, E, R):
    """
    Return the number of laps needed to charge the car
    """
    # Step 1: Calculate the perimeter of the rectangular car [cite: 15, 49]
    perimeter = 2 * (L + W)
    
    # Step 2: Calculate how much electricity is generated in one lap [cite: 49]
    # Big Ben moves 1 meter per step, so meters = steps [cite: 16]
    electricity_per_lap = perimeter * R
    
    # Step 3: Calculate total laps needed [cite: 50]
    # The result is guaranteed to be an integer [cite: 19, 38]
    laps_needed = E // electricity_per_lap
    
    return laps_needed3
5 3 128 2
10 5 300 10
2 2 400 5