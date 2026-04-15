def solve():
    number_of_test_cases = int(input())
    
    for _ in range(number_of_test_cases):
        number_of_floors = int(input())
        top_floor_heights = list(map(int, input().split()))
        
        sorted_heights = sorted(top_floor_heights)
        
        middle_index = number_of_floors // 2
        median_height = sorted_heights[middle_index]
        
        bottom_floor_heights = [median_height] * number_of_floors
        
        print(*bottom_floor_heights)


if __name__ == "__main__":
    solve()