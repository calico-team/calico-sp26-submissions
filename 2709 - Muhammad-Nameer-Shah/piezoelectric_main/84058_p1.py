def problem(L, W, R, E, num):
    area_covered = 2 * (L + W)
    full_cycle = area_covered * R
    battery = E / full_cycle
    
    return int(battery)