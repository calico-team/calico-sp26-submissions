num=int(input())
final=[]
for a in range(num):
    original=input()
    allowed=input()
    result=""
    for x in original:
        if len(allowed) > 0 and x == allowed[0]:
            result += x
            allowed = allowed[1:]
        else:
            result += "#"
    final.append(result)
    
for y in final:
    print(y)