def solve():
    number_of_tests = int(input())
    
    for _ in range(number_of_tests):
        original_string = input().strip()
        target_string = input().strip()
        
        result = []
        target_index = 0
        
        for current_char in original_string:
            if target_index < len(target_string) and current_char == target_string[target_index]:
                result.append(current_char)
                target_index += 1
            else:
                result.append('#')
        
        print(''.join(result))


if __name__ == "__main__":
    solve()    