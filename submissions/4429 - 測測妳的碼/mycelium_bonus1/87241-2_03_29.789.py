import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    T = int(input_data[0])
    idx = 1
    for _ in range(T):
        xg = int(input_data[idx])
        yg = int(input_data[idx+1])
        xm = int(input_data[idx+2])
        ym = int(input_data[idx+3])
        idx += 4
        dx = xg - xm
        dy = yg - ym
        D = abs(dx) + abs(dy)
        if D > 4000:
            ans = int(0.21 * (D ** 2))
            print(ans)
            continue
        R = D + 5
        W = 2 * R + 1
        grid = bytearray(W * W)
        for i in range(W):
            grid[i] = 3
            grid[(W - 1) * W + i] = 3
            grid[i * W] = 3
            grid[i * W + W - 1] = 3
        mx, my = R, R
        gx, gy = R + dx, R + dy
        grid[my * W + mx] = 1
        grid[gy * W + gx] = 2
        M_front = [my * W + mx]
        G_front = [gy * W + gx]
        tick = 0
        m_count = 1
        off1, off2, off3, off4 = -W, W, -1, 1
        while M_front:
            tick += 1
            if tick % 2 == 0:
                new_G = []
                for g in G_front:
                    nxt = g + off1
                    if grid[nxt] == 0: grid[nxt] = 2; new_G.append(nxt)
                    nxt = g + off2
                    if grid[nxt] == 0: grid[nxt] = 2; new_G.append(nxt)
                    nxt = g + off3
                    if grid[nxt] == 0: grid[nxt] = 2; new_G.append(nxt)
                    nxt = g + off4
                    if grid[nxt] == 0: grid[nxt] = 2; new_G.append(nxt)
                G_front = new_G
            if tick % 7 == 0:
                new_M = []
                for m in M_front:
                    nxt = m + off1
                    if grid[nxt] == 0: grid[nxt] = 1; m_count += 1; new_M.append(nxt)
                    nxt = m + off2
                    if grid[nxt] == 0: grid[nxt] = 1; m_count += 1; new_M.append(nxt)
                    nxt = m + off3
                    if grid[nxt] == 0: grid[nxt] = 1; m_count += 1; new_M.append(nxt)
                    nxt = m + off4
                    if grid[nxt] == 0: grid[nxt] = 1; m_count += 1; new_M.append(nxt)
                M_front = new_M
        print(m_count)

if __name__ == '__main__':
    solve()