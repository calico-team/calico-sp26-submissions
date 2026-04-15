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
        if D > 15000:
            print(int(0.21 * (D ** 2)))
            continue
        margin = int(0.45 * D) + 5
        min_x = min(-margin, dx - 1)
        max_x = max(margin, dx + 1)
        min_y = min(-margin, dy - 1)
        max_y = max(margin, dy + 1)
        W_x = max_x - min_x + 1
        W_y = max_y - min_y + 1
        if W_x * W_y > 250000000:
            print(int(0.21 * (D ** 2)))
            continue
        grid = bytearray(W_x * W_y)
        for i in range(W_x):
            grid[i] = 3
            grid[(W_y - 1) * W_x + i] = 3
        for i in range(W_y):
            grid[i * W_x] = 3
            grid[i * W_x + W_x - 1] = 3
        mx, my = 0 - min_x, 0 - min_y
        gx, gy = dx - min_x, dy - min_y
        grid[my * W_x + mx] = 1
        grid[gy * W_x + gx] = 2
        M_front = [my * W_x + mx]
        G_front = [gy * W_x + gx]
        tick = 0
        m_count = 1
        off1, off2, off3, off4 = -W_x, W_x, -1, 1
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