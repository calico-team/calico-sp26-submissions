def solve(a, b):
    result = list(a)
    b_index = 0
    
    for i, char in enumerate(a):
        if b_index < len(b) and char == b[b_index]:
            b_index += 1
        else:
            result[i] = "#"
            
    return "".join(result)

for t in range(int(input())):
    a = input()
    b = input()

    print(solve(a, b))