def censor_this_please(original, target):
    target_index = 0
    censored = []

    for letter in original:
        # Keep the letter if it matches the current needed character in target
        if target_index < len(target) and letter == target[target_index]:
            censored.append(letter)
            target_index += 1
        else:
            # Otherwise, replace it with '#'
            censored.append('#')

    return ''.join(censored)


# Sample test cases
test_cases = [
    ("ccaalliiccoo", "calico"),
    ("big_bens_bday", "bbb"),
    ("job", "jb"),
    ("include_over_californication", "ilovecalico"),
    ("six_seven_rizzler_sigma_banned_discord_skibidi_toilet", "severance")
]

# Run all test cases
for original, target in test_cases:
    result = censor_this_please(original, target)
    print(result)