import sys


def solve(P, A, B):
    """
    Build a factory grid that produces a target rate P / (2^A * 3^B).
    """
    if P == 0:
        return ["X"]

    def build_branch(a, b, p):
        total = (1 << a) * (3 ** b)
        if p == 0:
            return None
        if a == 0 and b == 0:
            return {"type": "collect", "size": 1}
        if p == total:
            return {"type": "collect", "size": total}
        if a > 0:
            half = total // 2
            left_p = min(p, half)
            right_p = p - left_p
            children = [build_branch(a - 1, b, left_p), build_branch(a - 1, b, right_p)]
            return {"type": "split2", "children": children}
        # b > 0
        third = total // 3
        c0 = min(p, third)
        c1 = min(max(p - third, 0), third)
        c2 = p - c0 - c1
        children = [build_branch(a, b - 1, c0), build_branch(a, b - 1, c1), build_branch(a, b - 1, c2)]
        return {"type": "split3", "children": children}

    root = build_branch(A, B, P)


    next_x = 0

    def assign_x(node):
        nonlocal next_x
        if node is None:
            return None
        if node["type"] == "collect":
            node["x"] = next_x
            node["width"] = 1
            next_x += 2
            return node["x"]
        active_children = [child for child in node["children"] if child is not None]
        child_xs = [assign_x(child) for child in active_children]
        left = child_xs[0]
        right = child_xs[-1]
        if len(child_xs) == 1:
            node["x"] = child_xs[0]
        else:
            node["x"] = (left + right) // 2
        node["width"] = (right - left) + 1
        return node["x"]

    assign_x(root)
    max_x = max(0, next_x - 1)

    max_depth = 0

    def compute_depth(node, depth):
        nonlocal max_depth
        if node is None:
            return
        max_depth = max(max_depth, depth)
        if node["type"] in ("split2", "split3"):
            for child in node["children"]:
                compute_depth(child, depth + 1)

    compute_depth(root, 0)
    rows = 2 * max_depth + 3
    cols = max_x + 3
    grid = [["."] * cols for _ in range(rows)]

    def place_path_to_edge(start_r, start_c):
        for r in range(start_r, rows):
            grid[r][start_c] = "v"

    def place_node(node, r):
        c = node["x"]
        if node["type"] == "collect":
            place_path_to_edge(r, c)
            return
        grid[r][c] = "S"
        directions = []
        if node["type"] == "split2":
            children = node["children"]
            active = [(i, child) for i, child in enumerate(children) if child is not None]
            if len(active) == 2:
                directions = [(-1, 0), (1, 0)]
            elif len(active) == 1:
                _, child = active[0]
                if child["x"] == c:
                    directions = [(0, 1)]
                else:
                    directions = [(1, 0)]
            else:
                directions = []
        
            output_dirs = []
            if len(active) == 2:
                output_dirs = [(-1, 0), (1, 0)]
            elif len(active) == 1:
                child = active[0][1]
                if child["x"] == c:
                    output_dirs = [(0, 1)]
                else:
                    output_dirs = [(1, 0)]
            child_index = 0
            for i in range(2):
                child = children[i]
                if child is None:
              
                    destroy_dir = (-1, 0) if i == 0 else (1, 0)
                    dr, dc = destroy_dir
                    grid[r + dr][c + dc] = "X"
                else:
                    target_dir = output_dirs[child_index]
                    child_index += 1
                    route_child(node, child, r, c, target_dir)
        else:
            children = node["children"]
            active = [(i, child) for i, child in enumerate(children) if child is not None]
            if len(active) == 3:
                output_dirs = [(-1, 0), (0, 1), (1, 0)]
            elif len(active) == 2:
                indices = [idx for idx, _ in active]
                if indices == [0, 1]:
                    output_dirs = [(-1, 0), (0, 1)]
                elif indices == [1, 2]:
                    output_dirs = [(0, 1), (1, 0)]
                else:
                    output_dirs = [(-1, 0), (1, 0)]
            elif len(active) == 1:
                single = active[0][1]
                if single["x"] == c:
                    output_dirs = [(0, 1)]
                else:
                    output_dirs = [(1, 0)]
            else:
                output_dirs = []
            dir_iter = iter(output_dirs)
            for i in range(3):
                child = children[i]
                if child is None:
                    if len(active) == 3:
                        continue 
                    if i == 0:
                        dr, dc = (-1, 0)
                    elif i == 1:
                        dr, dc = (0, 1)
                    else:
                        dr, dc = (1, 0)
                    if grid[r + dr][c + dc] == ".":
                        grid[r + dr][c + dc] = "X"
                else:
                    target_dir = next(dir_iter)
                    route_child(node, child, r, c, target_dir)

    def route_child(parent, child, r, c, target_dir):
        dr, dc = target_dir
        start_r = r + dr
        start_c = c + dc
        if dr == -1 and dc == 0:
            grid[start_r][start_c] = "<"
        elif dr == 1 and dc == 0:
            grid[start_r][start_c] = ">"
        elif dr == 0 and dc == 1:
            grid[start_r][start_c] = "v"
        elif dr == 0 and dc == -1:
            grid[start_r][start_c] = "v"

        dest_r = r + 2
        dest_c = child["x"]
        if target_dir == (-1, 0):
            for x in range(start_c, dest_c, -1):
                if x > dest_c:
                    grid[r][x] = "<"
            grid[r][dest_c] = "v"
            grid[r + 1][dest_c] = "v"
        elif target_dir == (1, 0):
            for x in range(start_c, dest_c):
                if x < dest_c:
                    grid[r][x] = ">"
            grid[r][dest_c] = "v"
            grid[r + 1][dest_c] = "v"
        elif target_dir == (0, 1):
            grid[r + 1][c] = "v"
            if dest_c != c:
                if dest_c < c:
                    grid[r + 1][c] = "<"
                    for x in range(c - 1, dest_c, -1):
                        grid[r + 1][x] = "<"
                    grid[r + 1][dest_c] = "v"
                else:
                    grid[r + 1][c] = ">"
                    for x in range(c + 1, dest_c):
                        grid[r + 1][x] = ">"
                    grid[r + 1][dest_c] = "v"
                grid[r + 2][dest_c] = "v"
        place_node(child, r + 2)

    place_node(root, 0)
    result = ["".join(row[:cols]) for row in grid]

    while len(result[0]) > 1 and all(row[-1] == "." for row in result):
        result = [row[:-1] for row in result]
    return result


def main():
    data = sys.stdin.read().strip().split()
    if not data:
        return
    it = iter(data)
    T = int(next(it))
    out_lines = []
    for _ in range(T):
        P = int(next(it))
        A = int(next(it))
        B = int(next(it))
        factory = solve(P, A, B)
        out_lines.append(f"{len(factory)} {len(factory[0])}")
        out_lines.extend(factory)
    sys.stdout.write("\n".join(out_lines))


if __name__ == '__main__':
    main()