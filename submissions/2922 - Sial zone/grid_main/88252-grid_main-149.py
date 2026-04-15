import heapq

T = int(input())

for _ in range(T):
    N = int(input())
    A = list(map(int, input().split()))
    
    # transform
    B = [A[i] - i for i in range(N)]
    
    heap = []
    res = [0] * N
    
    for i in range(N):
        heapq.heappush(heap, B[i])
        
        if heap[0] < B[i]:
            heapq.heappop(heap)
            heapq.heappush(heap, B[i])
        
        res[i] = heap[0]
    
    # reconstruct b
    for i in range(N):
        res[i] += i
    
    print(*res)