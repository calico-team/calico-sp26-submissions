def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    the_mutable_list_of_characters_from_initial_string_a = list(A)
    the_current_tracking_index_for_target_string_b = 0
    
    for the_iterator_variable_scanning_through_string_a in range(len(the_mutable_list_of_characters_from_initial_string_a)):
        
        if the_current_tracking_index_for_target_string_b < len(B) and the_mutable_list_of_characters_from_initial_string_a[the_iterator_variable_scanning_through_string_a] == B[the_current_tracking_index_for_target_string_b]:
            the_current_tracking_index_for_target_string_b += 1  
        else:
            the_mutable_list_of_characters_from_initial_string_a[the_iterator_variable_scanning_through_string_a] = '#'  
            
    return "".join(the_mutable_list_of_characters_from_initial_string_a)

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
