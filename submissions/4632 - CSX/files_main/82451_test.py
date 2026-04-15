T = int(input())
for i in range(T):
    A = input().strip()
    B = input().strip()
    result = ""
    current_b_position = 0
    length_of_b = len(B)
    for char in A:
        if current_b_position < length_of_b and char == B[current_b_position]:
            result += char
            current_b_position += 1
        else:
            result += "#"
    print(result)