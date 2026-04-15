#@title Problem 5
output=""
for _ in range(int(input())):
    N=int(input())
    A=list(map(int, input().split()))
    output+=" ".join([str(min(A[i:])) for i in range(N)])+"\n"
print(output)