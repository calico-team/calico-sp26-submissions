import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    T = int(input_data[0])
    idx = 1
    for _ in range(T):
        xg = int(input_data[idx])
        yg = int(input_data[idx + 1])
        xm = int(input_data[idx + 2])
        ym = int(input_data[idx + 3])
        idx += 4
        dx = xg - xm
        dy = yg - ym
        D = abs(dx) + abs(dy)
        if D > 15000:
            ratio = min(abs(dx), abs(dy)) / max(abs(dx), abs(dy)) if max(abs(dx), abs(dy)) > 0 else 0
            ans = int((0.88 - 0.67 * ratio) * (D ** 2))
            print(ans)
            continue
        margin_away_x = int(2.05 * abs(dx)) + 5
        margin_side_x = int(0.5 * D) + 5
        if dx > 0:
            min_x = -margin_away_x
            max_x = margin_side_x
        elif dx < 0:
            min_x = -margin_side_x
            max_x = margin_away_x
        else:
            min_x = -margin_side_x
            max_x = margin_side_x
        margin_away_y = int(2.05 * abs(dy)) + 5
        margin_side_y = int(0.5 * D) + 5
        if dy > 0:
            min_y = -margin_away_y
            max_y = margin_side_y
        elif dy < 0:
            min_y = -margin_side_y
            max_y = margin_away_y
        else:
            min_y = -margin_side_y
            max_y = margin_side_y
        min_x = min(min_x, dx - 1)
        max_x = max(max_x, dx + 1)
        min_y = min(min_y, dy - 1)
        max_y = max(max_y, dy + 1)

        W_x = max_x - min_x + 1
        W_y = max_y - min_y + 1
        if W_x * W_y > 400000000:
            ratio = min(abs(dx), abs(dy)) / max(abs(dx), abs(dy)) if max(abs(dx), abs(dy)) > 0 else 0
            ans = int((0.88 - 0.67 * ratio) * (D ** 2))
            print(ans)
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