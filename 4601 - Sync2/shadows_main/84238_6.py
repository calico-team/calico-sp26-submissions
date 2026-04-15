from itertools import product

def brute_force(n, s1, s2):
    valid = []
    for z in range(n):
        for x in range(n):
            for y in range(n):
                if s1[z][x] == '#' and s2[z][y] == '#':
                    valid.append((x,y,z))
    
    max_vol = len(valid)
    
    from itertools import combinations
    min_vol = max_vol
    
    for size in range(1, max_vol+1):
        found = False
        for subset in combinations(valid, size):
            ok = True
            
            for z in range(n):
                for x in range(n):
                    if s1[z][x] == '#':
                        if not any(bx==x and bz==z for bx,by,bz in subset):
                            ok = False; break
                if not ok: break
            if not ok: continue
            for z in range(n):
                for y in range(n):
                    if s2[z][y] == '#':
                        if not any(by==y and bz==z for bx,by,bz in subset):
                            ok = False; break
                if not ok: break
            if ok:
                found = True
                min_vol = size
                break
        if found:
            break
    
    return max_vol, min_vol