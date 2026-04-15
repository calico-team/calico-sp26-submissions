#T = int(input())
#for h in range(T):
A = input().strip()
B = input().strip()
result = ""
j = 0
for i in A:
    if j < len(B) and i == B[j]:
        result += i
        j += 1
    else:
        result += "#"
if j < len(B):
    print("impossible")
else:
    print(result)