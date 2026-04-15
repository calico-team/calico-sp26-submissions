cases = int(input())
output = []
for i in range(cases):
    length, width, need, rate = map(int, input().split())
    gain = 2 * rate * (length + width)
    output.append(str(need // gain))
print("\n".join(output))
