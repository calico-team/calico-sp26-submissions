def get_lap_amt():
    raw = input(" ").split(",")
    
    if len(raw) < 4:
        return
    
    L, W, E, R = map(int, raw)
    perimeter = (L * 2 + W * 2) * 2
    
    if perimeter == 0:
        return
    
    lap = E / perimeter
    print(f"Laps: {lap}")

get_lap_amt()
