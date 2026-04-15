from collections import deque
t = int(input())
for _ in range(t):
    data = [1, 2, 3, 4]
    o = list(input().split())
    n = int(o[0])
    m = int(o[1])
    room = [[0] * m for _ in range(n)]
    
    k = 1
    for i in range(k, n - k):
        for j in range(k, m - k):
            dq_h = deque(data[:3])
            for offset in range(-k, k + 1):
                room[i][j + offset] = dq_h.popleft()
                
            dq_v = deque(data[:3])
            for offset in range(-k, k + 1):
                room[i + offset][j] = dq_v.popleft()

    for row in room:
        print(*(row))
