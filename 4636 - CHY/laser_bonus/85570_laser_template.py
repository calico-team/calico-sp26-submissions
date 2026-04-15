def solve(k, n, m, p, q, x, y):
    x0 = x[0]
    y0 = y[0]
    min_t = float('inf')
    lazarbeam = -1
    for i in range(k):
        targets = [(q, (x[i] - x0) % n, n), (p, (y[i] - y0) % m, m)]
        res = []
        for a_val, b_val, mod_val in targets:
            a = a_val
            b = mod_val
            x_ext = 0
            last_x = 1
            while b != 0:
                q_div = a // b
                a, b = b, a % b
                last_x, x_ext = x_ext, last_x - q_div * x_ext
            if b_val % a != 0:
                break
            curr_mod = mod_val // a
            res.append(((last_x * (b_val // a)) % curr_mod, curr_mod))
        if len(res) < 2:
            continue
        (t1, m1), (t2, m2) = res
        a = m1
        b = m2
        x_ext = 0
        last_x = 1
        while b != 0:
            q_div = a // b
            a, b = b, a % b
            last_x, x_ext = x_ext, last_x - q_div * x_ext
        if (t2 - t1) % a != 0:
            continue
        c_mod = (m1 * m2) // a
        k_val = ((t2 - t1) // a * last_x) % (m2 // a)
        t_final = (t1 + k_val * m1) % c_mod
        if t_final == 0:
            t_final = c_mod
        if t_final < min_t:
            min_t = t_final
            lazarbeam = i
    return lazarbeam
def main():
    import sys
    data = sys.stdin.read().split()
    if not data:
        return
    it = iter(data)
    t_str = next(it, None)
    if t_str is None:
        return
    t_cases = int(t_str)
    for _ in range(t_cases):
        k_val = int(next(it))
        n_val = int(next(it))
        m_val = int(next(it))
        p_val = int(next(it))
        q_val = int(next(it))
        x_coords = []
        y_coords = []
        for _ in range(k_val):
            x_coords.append(int(next(it)))
            y_coords.append(int(next(it)))
        print(solve(k_val, n_val, m_val, p_val, q_val, x_coords, y_coords))
if __name__ == '__main__':
    main()
