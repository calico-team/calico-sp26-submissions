import sys
def solve():
    data = sys.stdin.read().split()
    if not data:
        return
    T = int(data[0])
    CurrentIndex = 1
    for i in range(T):
        A = data[CurrentIndex]
        B = data[CurrentIndex+1]
        CurrentIndex += 2 
        result = []
        j = 0
        for k in range(len(A)):
            if j < len(B) and A[k] == B[j]:
                result.append(A[k]) 
                j += 1 
            else:
                result.append('#')  
        print("".join(result))
solve()