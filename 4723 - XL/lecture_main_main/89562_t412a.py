import sys


def main():
    input = sys.stdin.read
    data = input().split()
    idx = 0
    t = int(data[idx])
    idx += 1
    res = []
    for _ in range(t):
        rows = int(data[idx])
        cols = int(data[idx + 1])
        req = int(data[idx + 2])
        idx += 3
        grid = []
        for _ in range(rows):
            grid.append(data[idx])
            idx += 1

        total = rows + cols - 1
        shift = cols - 1
        diag_list = [[] for _ in range(total)]

        for i in range(rows):
            line = grid[i]
            for j in range(cols):
                if line[j] == '-':
                    diag_list[i + j].append(i - j + shift)

        low = -1
        high = total - 1
        while high - low > 1:
            mid_val = (low + high) // 2
            count_arr = [0] * total
            valid = False
            ptr = -1
            max_u = total - mid_val
            max_v = total - mid_val

            for l in range(max_u):
                while ptr + 1 <= l + mid_val:
                    ptr += 1
                    for val in diag_list[ptr]:
                        count_arr[val] += 1

                current_sum = 0
                for x in range(mid_val + 1):
                    current_sum += count_arr[x]
                if current_sum >= req:
                    valid = True
                    break

                for d in range(1, max_v):
                    current_sum += count_arr[d + mid_val]
                    current_sum -= count_arr[d - 1]
                    if current_sum >= req:
                        valid = True
                        break

                if valid:
                    break
                for val in diag_list[l]:
                    count_arr[val] -= 1

            if valid:
                high = mid_val
            else:
                low = mid_val

        size = high
        count_arr = [0] * total
        ptr = -1
        final_u = 0
        final_v = 0
        found = False
        max_u = total - size
        max_v = total - size

        for l in range(max_u):
            while ptr + 1 <= l + size:
                ptr += 1
                for val in diag_list[ptr]:
                    count_arr[val] += 1

            current_sum = 0
            for x in range(size + 1):
                current_sum += count_arr[x]
            if current_sum >= req:
                final_u = l
                final_v = 0
                found = True
                break

            for d in range(1, max_v):
                current_sum += count_arr[d + size]
                current_sum -= count_arr[d - 1]
                if current_sum >= req:
                    final_u = l
                    final_v = d
                    found = True
                    break

            if found:
                break
            for val in diag_list[l]:
                count_arr[val] -= 1

        collected = 0
        for i in range(rows):
            if collected == req:
                break
            line = grid[i]
            for j in range(cols):
                if line[j] == '-':
                    u_val = i + j
                    v_val = i - j + shift
                    if final_u <= u_val <= final_u + size and final_v <= v_val <= final_v + size:
                        res.append(f"{i} {j}")
                        collected += 1
                        if collected == req:
                            break
    print('\n'.join(res))


if __name__ == "__main__":
    main()