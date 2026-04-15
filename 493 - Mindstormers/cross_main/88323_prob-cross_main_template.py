def solveProblem7():
    number_of_test_cases = int(input())
    
    for _ in range(number_of_test_cases):
        number_of_rows, number_of_columns = map(int, input().split())
        
        for row_index in range(number_of_rows):
            row_values = []
            
            for column_index in range(number_of_columns):
                value = (2 * row_index + column_index) % 5
                row_values.append(value)
            
            print(*row_values)


if __name__ == "__main__":
    solveProblem7()