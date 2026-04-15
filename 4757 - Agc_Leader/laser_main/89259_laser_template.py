import math

def solve(K, N, M, P, Q, X, Y):
    """
    Find the index of the first asteroid hit by the laser.
    
    K: Number of asteroids
    N, M: Bounds for x- and y-coordinates
    P, Q: Laser movement (P along y-axis, Q along x-axis)
    X: List of x-coordinates of asteroids
    Y: List of y-coordinates of asteroids
    """
    starting_asteroid_x_coordinate_value = X[0]
    starting_asteroid_y_coordinate_value = Y[0]
    
    # Helper function for modular inverse
    def calculate_modular_inverse_helper_function(value_to_invert, modulo_base_value):
        if modulo_base_value == 1:
            return 0
        return pow(value_to_invert, -1, modulo_base_value)
        
    # X-axis parameters
    greatest_common_divisor_of_step_and_grid_x_axis = math.gcd(Q, N)
    reduced_modulo_grid_bounds_n_prime = N // greatest_common_divisor_of_step_and_grid_x_axis
    reduced_laser_step_size_q_prime = Q // greatest_common_divisor_of_step_and_grid_x_axis
    modular_inverse_of_reduced_step_size_q = calculate_modular_inverse_helper_function(
        reduced_laser_step_size_q_prime, 
        reduced_modulo_grid_bounds_n_prime
    )
    
    # Y-axis parameters
    greatest_common_divisor_of_step_and_grid_y_axis = math.gcd(P, M)
    reduced_modulo_grid_bounds_m_prime = M // greatest_common_divisor_of_step_and_grid_y_axis
    reduced_laser_step_size_p_prime = P // greatest_common_divisor_of_step_and_grid_y_axis
    modular_inverse_of_reduced_step_size_p = calculate_modular_inverse_helper_function(
        reduced_laser_step_size_p_prime, 
        reduced_modulo_grid_bounds_m_prime
    )
    
    # CRT combination parameters
    greatest_common_divisor_of_the_two_reduced_moduli = math.gcd(reduced_modulo_grid_bounds_n_prime, reduced_modulo_grid_bounds_m_prime)
    factor_of_reduced_n_bounds_for_chinese_remainder_theorem = reduced_modulo_grid_bounds_n_prime // greatest_common_divisor_of_the_two_reduced_moduli
    factor_of_reduced_m_bounds_for_chinese_remainder_theorem = reduced_modulo_grid_bounds_m_prime // greatest_common_divisor_of_the_two_reduced_moduli
    modular_inverse_of_n_factor_for_chinese_remainder_theorem = calculate_modular_inverse_helper_function(
        factor_of_reduced_n_bounds_for_chinese_remainder_theorem, 
        factor_of_reduced_m_bounds_for_chinese_remainder_theorem
    )
    
    # Maximum possible wrap-around cycle
    least_common_multiple_of_maximum_possible_wrap_around_cycles = (reduced_modulo_grid_bounds_n_prime * reduced_modulo_grid_bounds_m_prime) // greatest_common_divisor_of_the_two_reduced_moduli
    
    absolute_minimum_number_of_steps_to_hit_any_asteroid = float('inf')
    final_index_of_the_first_asteroid_hit_by_the_laser = -1
    
    for current_asteroid_index_being_checked in range(K):
        current_asteroid_x_coordinate_value = X[current_asteroid_index_being_checked]
        current_asteroid_y_coordinate_value = Y[current_asteroid_index_being_checked]
        
        difference_in_x_coordinates_modulo_n_grid = (current_asteroid_x_coordinate_value - starting_asteroid_x_coordinate_value) % N
        difference_in_y_coordinates_modulo_m_grid = (current_asteroid_y_coordinate_value - starting_asteroid_y_coordinate_value) % M
        
        # If coordinates can't be reached by the step size independently, skip
        if difference_in_x_coordinates_modulo_n_grid % greatest_common_divisor_of_step_and_grid_x_axis != 0 or difference_in_y_coordinates_modulo_m_grid % greatest_common_divisor_of_step_and_grid_y_axis != 0:
            continue
            
        reduced_difference_in_x_coordinates = difference_in_x_coordinates_modulo_n_grid // greatest_common_divisor_of_step_and_grid_x_axis
        reduced_difference_in_y_coordinates = difference_in_y_coordinates_modulo_m_grid // greatest_common_divisor_of_step_and_grid_y_axis
        
        # Step counts required for x and y independently
        required_steps_for_x_coordinate_alignment_independently = (reduced_difference_in_x_coordinates * modular_inverse_of_reduced_step_size_q) % reduced_modulo_grid_bounds_n_prime
        required_steps_for_y_coordinate_alignment_independently = (reduced_difference_in_y_coordinates * modular_inverse_of_reduced_step_size_p) % reduced_modulo_grid_bounds_m_prime
        
        # If the step parities don't match up under their GCD, they never intersect
        if required_steps_for_x_coordinate_alignment_independently % greatest_common_divisor_of_the_two_reduced_moduli != required_steps_for_y_coordinate_alignment_independently % greatest_common_divisor_of_the_two_reduced_moduli:
            continue
            
        # Apply Chinese Remainder Theorem to find simultaneous intersection
        difference_between_required_y_and_x_alignment_steps = (required_steps_for_y_coordinate_alignment_independently - required_steps_for_x_coordinate_alignment_independently) // greatest_common_divisor_of_the_two_reduced_moduli
        multiplier_k_for_chinese_remainder_theorem_step_calculation = (difference_between_required_y_and_x_alignment_steps * modular_inverse_of_n_factor_for_chinese_remainder_theorem) % factor_of_reduced_m_bounds_for_chinese_remainder_theorem
        
        total_simultaneous_steps_required_for_laser_intersection = required_steps_for_x_coordinate_alignment_independently + multiplier_k_for_chinese_remainder_theorem_step_calculation * reduced_modulo_grid_bounds_n_prime
        
        # The laser must take at least 1 step (cannot hit asteroid 0 at step 0)
        if total_simultaneous_steps_required_for_laser_intersection == 0:
            total_simultaneous_steps_required_for_laser_intersection = least_common_multiple_of_maximum_possible_wrap_around_cycles
            
        # Track the earliest hit
        if total_simultaneous_steps_required_for_laser_intersection < absolute_minimum_number_of_steps_to_hit_any_asteroid:
            absolute_minimum_number_of_steps_to_hit_any_asteroid = total_simultaneous_steps_required_for_laser_intersection
            final_index_of_the_first_asteroid_hit_by_the_laser = current_asteroid_index_being_checked
            
    return final_index_of_the_first_asteroid_hit_by_the_laser

def main():
    
    T = int(input())

    for _ in range(T):
        line = input().split()
        K = int(line[0])
        N = int(line[1])
        M = int(line[2])
        P = int(line[3])
        Q = int(line[4])
        
        X = []
        Y = []
        for _ in range(K):
            coords = input().split()
            a_i = int(coords[0])
            b_i = int(coords[1])
            X.append(a_i)
            Y.append(b_i)

        print(solve(K, N, M, P, Q, X, Y))

if __name__ == '__main__':
    main()
    