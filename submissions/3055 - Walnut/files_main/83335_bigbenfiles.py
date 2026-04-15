count = int(input())
for i in range(count):
    source = input().strip()
    target = input().strip()
    place = 0
    built = []
    for letter in source:
        if place < len(target) and letter == target[place]:
            built.append(letter)
            place += 1
        else:
            built.append('#')
    print("".join(built))