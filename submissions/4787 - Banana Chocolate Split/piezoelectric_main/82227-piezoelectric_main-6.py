t = int(input())
for _ in range(t):
    lwer = list(map(int, input().split()))
    perimeter = (lwer[0] + lwer[1]) * 2
    e_per = perimeter * lwer[3]
    laps = lwer[2] // e_per
    print(laps)