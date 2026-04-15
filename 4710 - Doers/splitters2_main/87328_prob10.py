def solve(total_value, count_twos, count_threes):
    
    operations = []
    remaining_value = total_value
    
    a = count_twos
    b = count_threes
    
    for i in range(count_twos):
        a -= 1
        current_chunk = (2 ** a) * (3 ** b)
        
        if remaining_value >= current_chunk:
            operations.append(('2', True))
            remaining_value -= current_chunk
        else:
            operations.append(('2', False))
    
    for i in range(count_threes):
        b -= 1
        current_chunk = (2 ** a) * (3 ** b)
        
        take_top = False
        take_bottom = False
        
        if remaining_value >= 2 * current_chunk:
            take_top = True
            take_bottom = True
            remaining_value -= 2 * current_chunk
        
        elif remaining_value >= current_chunk:
            take_top = True
            remaining_value -= current_chunk
        
        operations.append(('3', take_top, take_bottom))
    
    total_steps = len(operations)
    width = 4 * total_steps + 1
    height = 3
    
    grid = [['.' for _ in range(width)] for _ in range(height)]
    
    grid[1][0] = '>'
    
    column = 1
    
    for op in operations:
        
        if op[0] == '2':
            _, took_top = op
            
            grid[1][column] = 'S'
            
            if took_top:
                grid[0][column] = '^'
            else:
                grid[0][column] = 'X'
            
            grid[1][column + 1] = '>'
            grid[1][column + 2] = '>'
            
            column += 3
        
        else:
            _, took_top, took_bottom = op
            
            grid[1][column] = 'S'
            
            if took_top:
                grid[0][column] = '^'
            else:
                grid[0][column] = 'X'
            
            if took_bottom:
                grid[2][column] = 'v'
            else:
                grid[2][column] = 'X'
            
            grid[1][column + 1] = '>'
            grid[1][column + 2] = '>'
            
            column += 3
    
    if remaining_value == 0:
        grid[1][column - 1] = 'X'
    
    result = []
    result.append(str(height) + " " + str(column))
    
    for r in range(height):
        result.append(''.join(grid[r][:column]))
    
    return "\n".join(result)


test_cases = int(input())

for _ in range(test_cases):
    total_value, num_twos, num_threes = map(int, input().split())
    print(solve(total_value, num_twos, num_threes))