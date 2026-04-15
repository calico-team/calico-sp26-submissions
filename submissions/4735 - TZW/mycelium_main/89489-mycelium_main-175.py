T = int(input())
for i in range(T):
    xg, yg, xm, ym = map(int, input().split())
    dx = abs(xg - xm)
    dy = abs(yg - ym)
    D = dx + dy
    t_g = 2
    t_m = 7
    LCM = 14
    k_max = (D - 1) // t_m
    total = 0
    for k in range(k_max + 1):
        t = k * t_m
        r_g = t // t_g
        rem = t % LCM
        if rem == 0:
            r_g -= 1
        free = max(0, D - 1 - r_g)
        total += 4 * k * free + 1
    print(total)
