inputs = [
    "ccaalliiccoo", "calico",
    "big_bens_bday", "bbb",
    "job", "jb",
    "include_over_californication", "ilovecalico",
    "six_seven_rizzler_sigma_banned_discord_skibidi_toilet", "severance"
]

for i in range(0, len(inputs), 2):
    a = inputs[i]
    b = inputs[i+1]
    
    res = ""
    j = 0  
    
    for char in a:
        if j < len(b) and char == b[j]:
            res = res + char
            j = j + 1
        else:
            res = res + '#'
            
    print(res)