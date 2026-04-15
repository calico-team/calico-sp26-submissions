import sys

sys.stdin = open('input.txt', 'r')

t = int(input().strip())

for i in range(t):
    a = input().strip()
    b = input().strip()
    
    res = ""
    j = 0  
    
    for char in a:
        if j < len(b) and char == b[j]:
            res =res + char
            j = j + 1
        else:
            res = res + '#'
            
    print(res)