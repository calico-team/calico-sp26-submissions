t = int(input())

for _ in range(t):
    full_text = input()
    word_to_find = input()
    
    shown_text = list('#' * len(full_text))
    letter_we_need_now = 0
    
    for position in range(len(full_text)):
        if letter_we_need_now < len(word_to_find) and full_text[position] == word_to_find[letter_we_need_now]:
            shown_text[position] = full_text[position]
            letter_we_need_now += 1
    
    print(''.join(shown_text))