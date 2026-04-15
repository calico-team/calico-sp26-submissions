
T = int(input())

def top_row(A):
    total = 0
    for i in range(1, len(A)):
        total += abs(A[i] - A[i-1])
    return total

def bottom_row(B):
    total = 0
    for i in range(1, len(B)):
        total += abs(B[i] - B[i-1])
    return total

def between_rows(A, B):
    total = 0
    for i in range(len(A)):
        total += abs(A[i] - B[i])
    return total

def find_most_common(A):
    counter = {}
    for num in A:
        if num not in counter:
            counter[num] = 1
        else:
            counter[num] += 1
    
    # return the element with max frequency
    return max(counter, key=counter.get)

for _ in range(T):
    N = int(input())
    A = list(map(int, input().split()))
    
    B1 = A[:]  # actual copy
    most_common = find_most_common(A)
    B2 = [most_common] * len(A)
    
    B_options = [B1, B2]
    
    min_sum = float('inf')
    ans = None

    for b in B_options:
        total = top_row(A) + bottom_row(b) + between_rows(A, b)
        if total < min_sum:
            min_sum = total
            ans = b
    
    print(ans)