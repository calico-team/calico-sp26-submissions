

def replace(a:str, b:str) -> str:

    result = []
    j = 0
    for i in a:
        if j < len(b) and i == b[j]:
            j += 1
            result.append(i)
        else:
            result.append("#")
    return ''.join(result)


a =input()
b =input()
print(replace(a,b))