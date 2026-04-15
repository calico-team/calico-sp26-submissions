test_cases = int(input())

for case in range(test_cases):
    number_of_asteroids, grid_width, grid_height, step_vertical, step_horizontal = map(int, input().split())
    
    asteroid_positions = []
    for i in range(number_of_asteroids):
        x_coordinate, y_coordinate = map(int, input().split())
        asteroid_positions.append((x_coordinate, y_coordinate))
    
    first_time_index = {}
    
    index = 0
    while index < len(asteroid_positions):
        x_coordinate = asteroid_positions[index][0]
        y_coordinate = asteroid_positions[index][1]
        
        if (x_coordinate, y_coordinate) not in first_time_index:
            first_time_index[(x_coordinate, y_coordinate)] = index
        
        index += 1
    
    current_x = asteroid_positions[0][0]
    current_y = asteroid_positions[0][1]
    
    answer = -1
    steps = 0
    max_steps = grid_width * grid_height
    
    while steps < max_steps:
        current_x = (current_x + step_horizontal) % grid_width
        current_y = (current_y + step_vertical) % grid_height
        
        if (current_x, current_y) in first_time_index:
            answer = first_time_index[(current_x, current_y)]
            break
        
        steps += 1
    
    print(answer)