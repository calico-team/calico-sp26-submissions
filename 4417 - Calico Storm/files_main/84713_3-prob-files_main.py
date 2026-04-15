T = int(input())

for _ in range(T):
    original = input()
    target = input()
    
    censored = []
    target_pos = 0
    
    for letter in original:
        if target_pos < len(target) and letter == target[target_pos]:
            censored.append(letter)
            target_pos += 1
        else:
            censored.append('#')
    
    print(''.join(censored))

def read_your_input():
    return map(int, input().split())