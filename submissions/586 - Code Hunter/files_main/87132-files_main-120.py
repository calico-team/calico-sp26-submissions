def censor_this_please(A, B):
    # Start from the end of B
    b_index = len(B) - 1
    
    # Initialize result with all '#'
    result = ['#'] * len(A)

    # Traverse A from right to left
    for i in range(len(A) - 1, -1, -1):
        if b_index >= 0 and A[i] == B[b_index]:
            result[i] = A[i]
            b_index -= 1

    return ''.join(result)


# Test cases (A and B in same file)
test_cases = [
    ("ccaalliiccoo", "calico"),
    ("big_bens_bday", "bbb"),
    ("job", "jb"),
    ("include_over_californication", "ilovecalico"),
    ("six_seven_rizzler_sigma_banned_discord_skibidi_toilet", "severance")
]

# Run test cases
for A, B in test_cases:
    print(censor_this_please(A, B))