number_of_tests = int(input())

for test_case in range(number_of_tests):
    
    size_of_list = int(input())
    values_in_list = input().split()
    
    for value in values_in_list:
        print(value, end=" ")
    
    print()