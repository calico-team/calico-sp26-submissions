import sys
# sys.stdin = open("3.in")
input = sys.stdin.readline

def solve():
    a = input().strip()
    b = input().strip()
    
    a = list(a)
    aPtr = 0
    for i in range(len(b)):
        while a[aPtr] != b[i]:
            a[aPtr] = "#"
            aPtr += 1
        aPtr += 1
    for i in range(aPtr, len(a)):
        a[i] = "#"
    print("".join(a))

tcs = int(input())

for tc in range(tcs):
    solve()

'''
greedy.
'''
