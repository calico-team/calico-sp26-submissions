T = int(input())

for _ in range(T):
    L,W,E,R = map(int, input().split())
    Long = (L+W)*2
    E_one = Long * R
    count = E / E_one
    count = int(count) if count.is_integer() else int(count) + 1
    print(count)