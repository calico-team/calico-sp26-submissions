tests = int(input())
for i in range(tests):
    size = int(input())
    first = [input().strip() for row in range(size)]
    second = [input().strip() for row in range(size)]
    most = 0
    least = 0
    for row in range(size):
        left = first[row].count('#')
        right = second[row].count('#')
        most += left * right
        least += max(left, right)
    print(most, least)