def censor_this_please(original_text, target_text):
    answer = []
    keep = [False] * len(original_text)
    target_index = 0
    place = 0
    for character in original_text:
        if target_index < len(target_text) and character == target_text[target_index]:
            keep[place] = True
            target_index += 1
        place += 1
    place = 0
    for character in original_text:
        if keep[place]:
            answer.append(character)
        else:
            answer.append("#")
        place += 1
    return "".join(answer)
def solve():
    test_cases = int(input())
    for _ in range(test_cases):
        original_text = input().strip()
        target_text = input().strip()
        print(censor_this_please(original_text, target_text))
def read_input():
    solve()
read_input()