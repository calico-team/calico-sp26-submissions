T = int(input())
for _ in range(T):
    n = int(input())
    s1, s2 = [], []

    for _ in range(n):
        row = input().strip()  
        s1.append(row)
    
    for _ in range(n):
        row = input().strip()
        s2.append(row)

    max_vol = 0
    min_vol = 0

    for z in range(n):
        r_z = s1[z].count('#')
        c_z = s2[z].count('#')
        max_vol += (r_z * c_z)
        min_vol += max(r_z, c_z)

    print(max_vol, min_vol)