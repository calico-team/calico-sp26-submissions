def censor_this_please(original, target):
    # Start matching from the end of target
    target_index = len(target) - 1
    
    # Start with everything censored
    result = ['#'] * len(original)

    # Go through original string from right to left
    for i in range(len(original) - 1, -1, -1):
        # If current character matches what we need in target
        if target_index >= 0 and original[i] == target[target_index]:
            result[i] = original[i]   # keep the character
            target_index -= 1         # move to next required character

    return ''.join(result)


# Sample test cases
test_cases = [
    ("ccaalliiccoo", "calico"),
    ("big_bens_bday", "bbb"),
    ("job", "jb"),
    ("include_over_californication", "ilovecalico"),
    ("six_seven_rizzler_sigma_banned_discord_skibidi_toilet", "severance")
]

# Run and print results
for original, target in test_cases:
    print(censor_this_please(original, target))