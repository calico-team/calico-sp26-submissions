import sys
input = sys.stdin.readline

def count_dx_in_range(lo, hi, slope, const, rhs):
    # Count integers dx in [lo,hi] where slope*dx < rhs - const
    # i.e. slope*dx < R where R = rhs - const
    if lo > hi:
        return 0
    R = rhs - const
    if slope == 0:
        return (hi - lo + 1) if 0 < R else 0
    elif slope > 0:
        # dx < R/slope
        max_dx = min(hi, (R - 1) // slope if R > 0 else (-((-R) // slope) - 1))
        # more carefully: largest integer dx with slope*dx < R
        # dx < R/slope => dx <= floor((R-1)/slope) if slope>0
        import math
        max_dx = min(hi, math.ceil(R / slope) - 1)
        return max(0, max_dx - lo + 1)
    else:
        # slope < 0: dx > R/slope
        import math
        min_dx = max(lo, math.floor(R / slope) + 1)
        return max(0, hi - min_dx + 1)

def count_row(dy, px, py, max_r):
    # Count integers dx in [-max_r, max_r] where
    # 7*(|dx|+|dy|) < 2*(|dx-px|+|dy-py|)
    # => 7*|dx| - 2*|dx-px| < 2*|dy-py| - 7*|dy|
    A = abs(dy)
    B = abs(dy - py)
    rhs = 2 * B - 7 * A
    
    # Split at dx=0 and dx=px
    import math
    breakpoints = sorted(set([0, px]))
    regions = []
    prev = -max_r
    for bp in breakpoints:
        regions.append((prev, bp - 1))
        prev = bp
    regions.append((prev, max_r))
    
    total = 0
    for (lo, hi) in regions:
        if lo > hi:
            continue
        mid = lo  # use lo to determine signs (constant within region)
        s1 = 1 if mid >= 0 else -1
        s2 = 1 if mid >= px else -1
        # 7*s1*dx - 2*s2*(dx-px) < rhs
        # (7*s1 - 2*s2)*dx + 2*s2*px < rhs
        slope = 7 * s1 - 2 * s2
        const = 2 * s2 * px
        total += count_dx_in_range(lo, hi, slope, const, rhs)
    
    return total

def solve(xg, yg, xm, ym):
    px = xg - xm
    py = yg - ym
    d = abs(px) + abs(py)
    max_r = (2 * d) // 5 + 5
    
    # For bonus3, max_r can be ~3.2e8, so we can't loop over dy
    # Need O(1) formula per quadrant
    # 
    # Count = sum over dy in [-max_r, max_r] of count_row(dy, px, py, max_r)
    # 
    # Split dy into regions based on sign of dy and dy-py
    # Within each region, rhs = 2*|dy-py| - 7*|dy| is linear in dy
    # And count_row is piecewise linear in dy too
    # 
    # This requires a fully analytical solution - compute sum of arithmetic series
    # per (dy-region, dx-region) combination
    
    # There are 4 combinations of (sign(dy), sign(dy-py)):
    # and within each, count_row has at most 3 dx-regions
    # giving 12 total regions, each with arithmetic series sum
    
    dy_breakpoints = sorted(set([0, py]))
    dy_regions = []
    prev = -max_r
    for bp in dy_breakpoints:
        dy_regions.append((prev, bp - 1))
        prev = bp
    dy_regions.append((prev, max_r))
    
    total = 0
    
    for (dy_lo, dy_hi) in dy_regions:
        if dy_lo > dy_hi:
            continue
        # Within this region, signs of dy and dy-py are constant
        dy_mid = dy_lo
        s_dy = 1 if dy_mid >= 0 else -1
        s_dypy = 1 if dy_mid >= py else -1
        
        # rhs(dy) = 2*s_dypy*(dy-py) - 7*s_dy*dy
        #         = (2*s_dypy - 7*s_dy)*dy - 2*s_dypy*py
        rhs_slope = 2 * s_dypy - 7 * s_dy
        rhs_const = -2 * s_dypy * py
        
        # For each dx region:
        dx_breakpoints = sorted(set([0, px]))
        dx_regions_list = []
        prev2 = -max_r
        for bp in dx_breakpoints:
            dx_regions_list.append((prev2, bp - 1))
            prev2 = bp
        dx_regions_list.append((prev2, max_r))
        
        for (dx_lo, dx_hi) in dx_regions_list:
            if dx_lo > dx_hi:
                continue
            dx_mid2 = dx_lo
            s1 = 1 if dx_mid2 >= 0 else -1
            s2 = 1 if dx_mid2 >= px else -1
            # condition: (7*s1 - 2*s2)*dx + 2*s2*px < rhs(dy)
            # = rhs_slope*dy + rhs_const
            f_slope = 7 * s1 - 2 * s2
            f_const = 2 * s2 * px
            
            # For each dy in [dy_lo, dy_hi], count dx in [dx_lo, dx_hi] where:
            # f_slope*dx < rhs_slope*dy + rhs_const - f_const
            # Let R(dy) = rhs_slope*dy + rhs_const - f_const
            
            # count_dx(dy) = number of integers dx in [dx_lo,dx_hi] with f_slope*dx < R(dy)
            
            import math
            
            def count_for_dy(dy):
                R = rhs_slope * dy + rhs_const - f_const
                if f_slope == 0:
                    return (dx_hi - dx_lo + 1) if 0 < R else 0
                elif f_slope > 0:
                    max_dx = min(dx_hi, math.ceil(R / f_slope) - 1)
                    return max(0, max_dx - dx_lo + 1)
                else:
                    min_dx = max(dx_lo, math.floor(R / f_slope) + 1)
                    return max(0, dx_hi - min_dx + 1)
            
            # count_for_dy is a piecewise linear (actually piecewise constant step)
            # function of dy. As dy increases by 1, R changes by rhs_slope.
            # The threshold for dx changes when R crosses a multiple of f_slope.
            # 
            # Sum over dy in [dy_lo, dy_hi] of count_for_dy(dy)
            # 
            # If f_slope == 0: easy
            if f_slope == 0:
                R_any = rhs_slope * dy_lo + rhs_const - f_const
                # Actually R changes with dy if rhs_slope != 0
                # Need to count dy where 0 < R(dy)
                # R(dy) = rhs_slope*dy + C where C = rhs_const - f_const
                C2 = rhs_const - f_const
                if rhs_slope == 0:
                    if 0 < C2:
                        total += (dy_hi - dy_lo + 1) * (dx_hi - dx_lo + 1)
                else:
                    # R(dy) > 0 iff rhs_slope*dy > -C2
                    if rhs_slope > 0:
                        min_dy = max(dy_lo, math.ceil((-C2 + 1) / rhs_slope) if rhs_slope > 0 else dy_lo)
                        # rhs_slope*dy > -C2 => dy > -C2/rhs_slope
                        threshold = math.floor(-C2 / rhs_slope) + 1
                        min_dy = max(dy_lo, threshold)
                        if min_dy <= dy_hi:
                            total += (dy_hi - min_dy + 1) * (dx_hi - dx_lo + 1)
                    else:
                        threshold = math.ceil(-C2 / rhs_slope)  # dy < threshold
                        max_dy = min(dy_hi, threshold - 1)
                        if dy_lo <= max_dy:
                            total += (max_dy - dy_lo + 1) * (dx_hi - dx_lo + 1)
                continue
            
            # f_slope != 0
            # count_for_dy(dy) = clamp(floor((R(dy)-1)/f_slope) - dx_lo + 1, 0, dx_hi-dx_lo+1) if f_slope>0
            # or similar for f_slope<0
            # R(dy) = rhs_slope*dy + (rhs_const - f_const)
            # This is an arithmetic progression in dy
            # Sum = sum of arithmetic series of counts
            # 
            # Use the formula: sum_{dy=dy_lo}^{dy_hi} max(0, min(W, floor((R(dy)-eps)/|f_slope|) + offset))
            # where W = dx_hi - dx_lo + 1
            # 
            # This is a standard "count lattice points under a line" problem
            # solvable in O(1) using arithmetic series
            
            W = dx_hi - dx_lo + 1
            
            # For f_slope > 0: count = max(0, min(W, ceil(R/f_slope)-1 - dx_lo + 1))
            #                        = max(0, min(W, ceil(R/f_slope) - dx_lo))
            # For f_slope < 0: count = max(0, min(W, dx_hi - floor(R/f_slope)))
            
            # Compute sum over dy in [dy_lo, dy_hi]
            # R(dy) = rhs_slope*dy + K, K = rhs_const - f_const
            K = rhs_const - f_const
            
            def sum_counts(dy_a, dy_b):
                if dy_a > dy_b:
                    return 0
                s = 0
                for dy in range(dy_a, dy_b + 1):
                    s += count_for_dy(dy)
                return s
            
            # For small ranges use direct; for large use formula
            span = dy_hi - dy_lo + 1
            if span <= 2000:
                for dy in range(dy_lo, dy_hi + 1):
                    total += count_for_dy(dy)
            else:
                # Use arithmetic series formula
                # count_for_dy(dy) as function of dy:
                # if f_slope > 0: c(dy) = max(0, min(W, ceil(R(dy)/f_slope) - dx_lo))
                # R(dy) increases/decreases linearly with dy
                # The count changes by 1 every |f_slope/rhs_slope| steps
                # 
                # Total = sum of arithmetic series
                # Use: sum_{dy=a}^{b} floor(alpha*dy + beta) type formula
                # 
                # Approximate with direct summation using the fact that
                # count changes slowly - iterate over "steps" where count changes
                
                # Find range of dy where count is in [0, W]
                # count_for_dy is monotone in dy (if rhs_slope and f_slope have same/diff signs)
                
                # Strategy: find breakpoints where count changes, sum each segment
                # count changes when R(dy) crosses a multiple of f_slope
                # i.e. when rhs_slope*dy + K crosses f_slope * k for integer k
                # i.e. dy crosses (f_slope*k - K) / rhs_slope
                
                if rhs_slope == 0:
                    # R constant
                    c = count_for_dy(dy_lo)
                    total += c * span
                else:
                    # count_for_dy changes at most W times total across the range
                    # Use direct loop but only iterate over change points
                    # 
                    # Actually for bonus3, rhs_slope can be up to 9, f_slope up to 9
                    # and span up to ~6.4e8, so we need O(W) = O(d/5) iterations
                    # which is still up to ~1.6e8 - too slow
                    # 
                    # Need fully closed form
                    # sum_{dy=a}^{b} max(0, min(W, ceil((rhs_slope*dy+K)/f_slope) - dx_lo))
                    # 
                    # Let's use the formula for sum of floor/ceil of arithmetic progression
                    
                    # Rewrite count_for_dy for f_slope > 0:
                    # c(dy) = max(0, min(W, ceil((rs*dy+K)/fs) - dxlo))
                    # where rs=rhs_slope, fs=f_slope
                    # ceil(x/fs) = floor((x-1)/fs)+1 for integer x, fs>0
                    # = floor((rs*dy+K-1)/fs) + 1 - dxlo
                    # Let v(dy) = floor((rs*dy + K - 1) / fs) + 1 - dxlo
                    # c(dy) = max(0, min(W, v(dy)))
                    # sum c(dy) = sum max(0,min(W,v(dy)))
                    # = sum_{v>=W} W + sum_{0<v<W} v + sum_{v<=0} 0
                    # Need to find ranges of dy for each case
                    
                    # v(dy) >= W iff floor((rs*dy+K-1)/fs) >= W+dxlo-1
                    # iff rs*dy+K-1 >= fs*(W+dxlo-1) [if rs>0] or ...
                    # 
                    # This is getting complex. Let's just do it with the
                    # sum of floor of arithmetic sequence formula (like floor sum)
                    
                    # sum_{dy=a}^{b} floor((rs*dy + C0) / fs)
                    # Use the standard floor_sum algorithm (O(log) like Euclidean)
                    
                    def floor_sum(n, a, b, m):
                        # sum_{i=0}^{n-1} floor((a*i + b) / m), m>0
                        # Standard algorithm
                        if n == 0:
                            return 0
                        res = 0
                        if a >= m:
                            res += n * (n-1) // 2 * (a // m)
                            a %= m
                        if b >= m:
                            res += n * (b // m)
                            b %= m
                        y_max = (a * n + b) // m
                        if y_max == 0:
                            return res
                        x_max = y_max * m - b
                        res += (n - (x_max + a - 1) // a) * y_max
                        res += floor_sum(y_max, m, (a - x_max % a) % a, a)
                        return res
                    
                    rs = rhs_slope
                    fs = abs(f_slope)
                    
                    if f_slope > 0:
                        # v(dy) = floor((rs*dy + K - 1) / fs) + 1 - dx_lo
                        # c(dy) = max(0, min(W, v(dy)))
                        # 
                        # Find dy ranges: v<=0, 0<v<W, v>=W
                        # v(dy) = floor((rs*dy + K-1)/fs) + 1 - dx_lo
                        # v(dy) <= 0 iff floor((rs*dy+K-1)/fs) <= dx_lo - 1
                        # v(dy) >= W iff floor((rs*dy+K-1)/fs) >= W + dx_lo - 1
                        
                        C0 = K - 1
                        
                        # For each dy, raw_v = floor((rs*dy+C0)/fs)
                        # v = raw_v + 1 - dx_lo
                        # c = max(0, min(W, v))
                        
                        # Find thresholds
                        # v <= 0: raw_v <= dx_lo - 1 => rs*dy + C0 < fs*dx_lo (if rs>0)
                        # v >= W: raw_v >= W+dx_lo-1 => rs*dy+C0 >= fs*(W+dx_lo-1) [if rs>0]
                        
                        # Handle rs=0 separately
                        if rs == 0:
                            c = count_for_dy(dy_lo)
                            total += c * span
                        elif rs > 0:
                            # v increasing with dy
                            # Find dy where v first becomes >0: rs*dy+C0 >= fs*(dx_lo-1)+1? 
                            # raw_v >= dx_lo - 1 iff rs*dy >= fs*(dx_lo-1) - C0
                            # dy >= ceil((fs*(dx_lo-1) - C0) / rs)
                            import math
                            
                            t1_num = fs * (dx_lo - 1) - C0  # v>0 when rs*dy+C0 >= fs*(dx_lo-1)+1? 
                            # Actually v>0 iff raw_v >= dx_lo: rs*dy+C0 >= fs*dx_lo
                            # dy >= ceil((fs*dx_lo - C0)/rs)
                            t1 = math.ceil((fs * dx_lo - C0) / rs)  # first dy where v > 0
                            # v>=W iff raw_v >= W+dx_lo-1: rs*dy+C0 >= fs*(W+dx_lo-1)
                            t2 = math.ceil((fs * (W + dx_lo - 1) - C0) / rs)  # first dy where v >= W
                            
                            # Region 1: dy in [dy_lo, t1-1]: c=0
                            # Region 2: dy in [t1, t2-1]: c=v=raw_v+1-dx_lo
                            # Region 3: dy in [t2, dy_hi]: c=W
                            
                            r1_lo, r1_hi = dy_lo, min(dy_hi, t1 - 1)
                            r2_lo, r2_hi = max(dy_lo, t1), min(dy_hi, t2 - 1)
                            r3_lo, r3_hi = max(dy_lo, t2), dy_hi
                            
                            # Region 3: sum = W * count
                            if r3_lo <= r3_hi:
                                total += W * (r3_hi - r3_lo + 1)
                            
                            # Region 2: sum = sum of (floor((rs*dy+C0)/fs) + 1 - dx_lo)
                            # = sum floor((rs*dy+C0)/fs) + (1-dx_lo)*(r2_hi-r2_lo+1)
                            if r2_lo <= r2_hi:
                                n2 = r2_hi - r2_lo + 1
                                # sum_{dy=r2_lo}^{r2_hi} floor((rs*dy+C0)/fs)
                                # = sum_{i=0}^{n2-1} floor((rs*(r2_lo+i)+C0)/fs)
                                # = sum_{i=0}^{n2-1} floor((rs*i + rs*r2_lo+C0)/fs)
                                b0 = rs * r2_lo + C0
                                # Need to handle negative b0 and rs for floor_sum
                                # floor_sum requires a>=0, b>=0, m>0
                                # General: sum floor((a*i+b)/m) for i=0..n-1
                                # Use: if a<0 or b<0, adjust
                                
                                # Direct sum for safety (region 2 size bounded by W <= dx_range)
                                for dy in range(r2_lo, r2_hi + 1):
                                    total += count_for_dy(dy)
                        else:  # rs < 0
                            # v decreasing with dy
                            import math
                            t2 = math.floor((fs * (W + dx_lo - 1) - C0) / rs)  # last dy where v>=W
                            t1 = math.floor((fs * dx_lo - C0) / rs)  # last dy where v>0
                            
                            r3_lo, r3_hi = dy_lo, min(dy_hi, t2)
                            r2_lo, r2_hi = max(dy_lo, t2 + 1), min(dy_hi, t1)
                            r1_lo, r1_hi = max(dy_lo, t1 + 1), dy_hi
                            
                            if r3_lo <= r3_hi:
                                total += W * (r3_hi - r3_lo + 1)
                            if r2_lo <= r2_hi:
                                for dy in range(r2_lo, r2_hi + 1):
                                    total += count_for_dy(dy)
                    
                    else:  # f_slope < 0
                        # c(dy) = max(0, min(W, dx_hi - floor(R(dy)/|fs|)))
                        # Similar analysis, omitted for brevity - use direct loop for middle region
                        for dy in range(dy_lo, dy_hi + 1):
                            total += count_for_dy(dy)
    
    return total

def solve(xg, yg, xm, ym):
    px = xg - xm
    py = yg - ym
    d = abs(px) + abs(py)
    max_r = (2 * d) // 5 + 5
    return count_full(px, py, max_r)

def count_full(px, py, max_r):
    # Simple O(max_r) per-row counting - works for bonus2
    # For bonus3 need O(1) but let's submit what we have
    d = abs(px) + abs(py)
    max_r = (2 * d) // 5 + 5
    
    total = 0
    import math
    
    dy_breakpoints = sorted(set([0, py]))
    dy_regions = []
    prev = -max_r
    for bp in dy_breakpoints:
        dy_regions.append((prev, bp - 1))
        prev = bp
    dy_regions.append((prev, max_r))
    
    for (dy_lo, dy_hi) in dy_regions:
        if dy_lo > dy_hi:
            continue
        dy_mid = dy_lo
        s_dy = 1 if dy_mid >= 0 else -1
        s_dypy = 1 if dy_mid >= py else -1
        rhs_slope = 2 * s_dypy - 7 * s_dy
        rhs_const = -2 * s_dypy * py
        
        dx_breakpoints = sorted(set([0, px]))
        dx_regions_list = []
        prev2 = -max_r
        for bp in dx_breakpoints:
            dx_regions_list.append((prev2, bp - 1))
            prev2 = bp
        dx_regions_list.append((prev2, max_r))
        
        for (dx_lo, dx_hi) in dx_regions_list:
            if dx_lo > dx_hi:
                continue
            dx_mid2 = dx_lo
            s1 = 1 if dx_mid2 >= 0 else -1
            s2 = 1 if dx_mid2 >= px else -1
            f_slope = 7 * s1 - 2 * s2
            f_const = 2 * s2 * px
            K = rhs_const - f_const
            rs = rhs_slope
            fs = f_slope
            W = dx_hi - dx_lo + 1
            
            def count_for_dy(dy):
                R = rs * dy + K
                if fs == 0:
                    return W if 0 < R else 0
                elif fs > 0:
                    max_dx = min(dx_hi, math.ceil(R / fs) - 1)
                    return max(0, max_dx - dx_lo + 1)
                else:
                    min_dx = max(dx_lo, math.floor(R / fs) + 1)
                    return max(0, dx_hi - min_dx + 1)
            
            span = dy_hi - dy_lo + 1
            
            if fs == 0:
                if rs == 0:
                    if 0 < K:
                        total += span * W
                else:
                    # Count dy where rs*dy + K > 0
                    if rs > 0:
                        threshold = math.ceil(-K / rs + 1) if K < 0 else (math.ceil((-K)/rs)+1 if K >= 0 else 1)
                        threshold = -(-(-K-1)//rs) if rs > 0 else 0  # dy > -K/rs
                        threshold = math.floor((-K-1)/rs) + 1 if rs > 0 else 0
                        # rs*dy > -K => dy > -K/rs
                        if rs > 0:
                            min_dy = max(dy_lo, math.floor(-K/rs) + 1)
                            if min_dy <= dy_hi:
                                total += (dy_hi - min_dy + 1) * W
                        else:
                            max_dy = min(dy_hi, math.ceil(-K/rs) - 1)
                            if dy_lo <= max_dy:
                                total += (max_dy - dy_lo + 1) * W
                continue
            
            # fs != 0
            if rs == 0:
                c = count_for_dy(dy_lo)
                total += c * span
                continue
            
            # Both nonzero - find three regions
            # Region where count=0, 0<count<W, count=W
            if fs > 0:
                # count > 0 when R > 0: rs*dy + K > 0
                # count = W when R > fs*(dx_hi-dx_lo+1)+... actually when ceil(R/fs)-1 >= dx_hi
                # i.e. R > fs*dx_hi => rs*dy+K > fs*dx_hi
                # count = 0 when R <= 0: rs*dy+K <= 0 => rs*dy <= -K
                
                if rs > 0:
                    t_pos = max(dy_lo, math.floor(-K/rs) + 1)  # first dy where R>0
                    t_full = max(dy_lo, math.floor((fs*dx_hi - K)/rs) + 1)  # first dy where count=W
                    
                    # [dy_lo, t_pos-1]: count=0
                    # [t_pos, t_full-1]: 0<count<W - use direct sum
                    # [t_full, dy_hi]: count=W
                    
                    r2_lo = max(dy_lo, t_pos)
                    r2_hi = min(dy_hi, t_full - 1)
                    r3_lo = max(dy_lo, t_full)
                    r3_hi = dy_hi
                    
                    if r3_lo <= r3_hi:
                        total += W * (r3_hi - r3_lo + 1)
                    if r2_lo <= r2_hi:
                        # Middle region: sum of arithmetic-like series
                        # count(dy) = ceil((rs*dy+K)/fs) - 1 - dx_lo + 1
                        #           = ceil((rs*dy+K)/fs) - dx_lo
                        # sum = sum ceil((rs*dy+K)/fs) - dx_lo * n
                        # ceil(x/fs) = floor((x+fs-1)/fs) = floor((rs*dy+K+fs-1)/fs)
                        # sum floor((rs*dy + K+fs-1)/fs) - dx_lo*n
                        # Use floor_sum
                        n2 = r2_hi - r2_lo + 1
                        # sum_{i=0}^{n2-1} floor((rs*(r2_lo+i) + K+fs-1)/fs)
                        a_coef = rs
                        b_coef = rs * r2_lo + K + fs - 1
                        m_coef = fs
                        
                        # floor_sum needs a>=0, b>=0 (adjust for negatives)
                        # General floor sum:
                        def gen_floor_sum(n, a, b, m):
                            # sum_{i=0}^{n-1} floor((a*i+b)/m)
                            # handles negative a, b
                            if n == 0:
                                return 0
                            # Normalize b to [0, m)
                            if m < 0:
                                a, b, m = -a, -b, -m
                            # Now m > 0
                            # floor((a*i+b)/m) = floor(a/m)*i + floor(b/m) + floor(((a%m)*i + (b%m))/m)
                            q_a = a // m if a >= 0 else -((-a + m - 1) // m)
                            r_a = a - q_a * m
                            q_b = b // m if b >= 0 else -((-b + m - 1) // m)
                            r_b = b - q_b * m
                            base = q_a * n * (n-1) // 2 + q_b * n
                            # Now sum floor((r_a*i + r_b)/m) for i=0..n-1, 0<=r_a<m, 0<=r_b<m
                            # Standard floor_sum algorithm
                            def fs_nonneg(n, a, b, m):
                                if n == 0 or a == 0:
                                    return n * (b // m)
                                res = 0
                                if a >= m:
                                    res += n * (n-1) // 2 * (a // m)
                                    a %= m
                                if b >= m:
                                    res += n * (b // m)
                                    b %= m
                                y_max = (a * n + b) // m
                                if y_max == 0:
                                    return res
                                res += y_max * (n - 1) - fs_nonneg(y_max, m, m - b - 1, a)
                                return res
                            return base + fs_nonneg(n, r_a, r_b, m)
                        
                        s = gen_floor_sum(n2, a_coef, b_coef, m_coef)
                        total += s - dx_lo * n2
                
                else:  # rs < 0, count decreasing
                    t_full = min(dy_hi, math.ceil((fs*dx_hi - K)/rs) - 1)  # last dy where count=W
                    t_pos = min(dy_hi, math.ceil(-K/rs) - 1)  # last dy where R>0
                    
                    r3_lo = dy_lo
                    r3_hi = min(dy_hi, t_full)
                    r2_lo = max(dy_lo, t_full + 1)
                    r2_hi = min(dy_hi, t_pos)
                    
                    if r3_lo <= r3_hi:
                        total += W * (r3_hi - r3_lo + 1)
                    if r2_lo <= r2_hi:
                        n2 = r2_hi - r2_lo + 1
                        a_coef = rs
                        b_coef = rs * r2_lo + K + fs - 1
                        m_coef = fs
                        
                        def gen_floor_sum2(n, a, b, m):
                            if n == 0:
                                return 0
                            if m < 0:
                                a, b, m = -a, -b, -m
                            q_a = a // m if a >= 0 else -((-a + m - 1) // m)
                            r_a = a - q_a * m
                            q_b = b // m if b >= 0 else -((-b + m - 1) // m)
                            r_b = b - q_b * m
                            base = q_a * n * (n-1) // 2 + q_b * n
                            def fs_nonneg(n, a, b, m):
                                if n == 0 or a == 0:
                                    return n * (b // m)
                                res = 0
                                if a >= m:
                                    res += n * (n-1) // 2 * (a // m)
                                    a %= m
                                if b >= m:
                                    res += n * (b // m)
                                    b %= m
                                y_max = (a * n + b) // m
                                if y_max == 0:
                                    return res
                                res += y_max * (n - 1) - fs_nonneg(y_max, m, m - b - 1, a)
                                return res
                            return base + fs_nonneg(n, r_a, r_b, m)
                        
                        s = gen_floor_sum2(n2, a_coef, b_coef, m_coef)
                        total += s - dx_lo * n2
            
            else:  # fs < 0
                # count = max(0, min(W, dx_hi - floor(R/|fs|) + 1)) -- need to rederive
                # c(dy) = dx_hi - floor(R(dy)/fs) [since fs<0, floor(R/fs) is floor of negative]
                # Actually: min_dx = floor(R/fs)+1, count = dx_hi - min_dx + 1
                # = dx_hi - floor(R(dy)/fs)
                # count > 0 when dx_hi > floor(R/fs), i.e. floor(R/fs) < dx_hi
                # count = W when floor(R/fs) <= dx_lo - 1, i.e. R/fs < dx_lo (careful with neg)
                
                # fs < 0: floor(R/fs) 
                # R(dy) = rs*dy + K
                # floor(R/fs): as dy increases, R changes, and since fs<0, floor(R/fs) changes oppositely
                
                # For simplicity, use direct loop for fs<0 cases
                # (fs<0 means s1=-1,s2=1 or s1=1,s2=-1 giving fs=-9 or fs=5... wait)
                # fs = 7*s1 - 2*s2: possible values: 7-2=5, 7+2=9, -7-2=-9, -7+2=-5
                # fs<0 only when s1=-1: fs=-9 or fs=-5
                
                if rs > 0:
                    # R increasing, count=dx_hi-floor(R/fs) 
                    # floor(R/fs) decreasing (fs<0)
                    # count increasing
                    t_pos = max(dy_lo, math.floor((fs * dx_hi - K) / rs) + 1)  # first dy where count>0
                    # count=W: dx_hi - floor(R/fs) >= W => floor(R/fs) <= dx_lo-1
                    # R/fs <= dx_lo-1 (careful: fs<0, dividing flips inequality)
                    # R >= fs*(dx_lo-1) [flip due to fs<0]
                    t_full = max(dy_lo, math.ceil((fs * (dx_lo - 1) - K) / rs))
                    
                    r2_lo = max(dy_lo, t_pos)
                    r2_hi = min(dy_hi, t_full - 1)
                    r3_lo = max(dy_lo, t_full)
                    r3_hi = dy_hi
                    
                    if r3_lo <= r3_hi:
                        total += W * (r3_hi - r3_lo + 1)
                    if r2_lo <= r2_hi:
                        # count = dx_hi - floor((rs*dy+K)/fs)
                        # sum = (r2_hi-r2_lo+1)*dx_hi - sum floor((rs*dy+K)/fs)
                        n2 = r2_hi - r2_lo + 1
                        
                        def gen_floor_sum3(n, a, b, m):
                            if n == 0:
                                return 0
                            if m < 0:
                                a, b, m = -a, -b, -m
                            q_a = a // m if a >= 0 else -((-a + m - 1) // m)
                            r_a = a - q_a * m
                            q_b = b // m if b >= 0 else -((-b + m - 1) // m)
                            r_b = b - q_b * m
                            base = q_a * n * (n-1) // 2 + q_b * n
                            def fs_nonneg(n, a, b, m):
                                if n == 0 or a == 0:
                                    return n * (b // m)
                                res = 0
                                if a >= m:
                                    res += n * (n-1) // 2 * (a // m)
                                    a %= m
                                if b >= m:
                                    res += n * (b // m)
                                    b %= m
                                y_max = (a * n + b) // m
                                if y_max == 0:
                                    return res
                                res += y_max * (n - 1) - fs_nonneg(y_max, m, m - b - 1, a)
                                return res
                            return base + fs_nonneg(n, r_a, r_b, m)
                        
                        s = gen_floor_sum3(n2, rs, rs * r2_lo + K, fs)
                        total += n2 * dx_hi - s
                
                else:  # rs < 0
                    t_full = min(dy_hi, math.floor((fs * (dx_lo - 1) - K) / rs))
                    t_pos = min(dy_hi, math.floor((fs * dx_hi - K) / rs))
                    
                    r3_lo = dy_lo
                    r3_hi = min(dy_hi, t_full)
                    r2_lo = max(dy_lo, t_full + 1)
                    r2_hi = min(dy_hi, t_pos)
                    
                    if r3_lo <= r3_hi:
                        total += W * (r3_hi - r3_lo + 1)
                    if r2_lo <= r2_hi:
                        n2 = r2_hi - r2_lo + 1
                        
                        def gen_floor_sum4(n, a, b, m):
                            if n == 0:
                                return 0
                            if m < 0:
                                a, b, m = -a, -b, -m
                            q_a = a // m if a >= 0 else -((-a + m - 1) // m)
                            r_a = a - q_a * m
                            q_b = b // m if b >= 0 else -((-b + m - 1) // m)
                            r_b = b - q_b * m
                            base = q_a * n * (n-1) // 2 + q_b * n
                            def fs_nonneg(n, a, b, m):
                                if n == 0 or a == 0:
                                    return n * (b // m)
                                res = 0
                                if a >= m:
                                    res += n * (n-1) // 2 * (a // m)
                                    a %= m
                                if b >= m:
                                    res += n * (b // m)
                                    b %= m
                                y_max = (a * n + b) // m
                                if y_max == 0:
                                    return res
                                res += y_max * (n - 1) - fs_nonneg(y_max, m, m - b - 1, a)
                                return res
                            return base + fs_nonneg(n, r_a, r_b, m)
                        
                        s = gen_floor_sum4(n2, rs, rs * r2_lo + K, fs)
                        total += n2 * dx_hi - s
    
    return total

import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    xg, yg, xm, ym = map(int, input().split())
    print(solve(xg, yg, xm, ym))