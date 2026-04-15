from fractions import Fraction
from collections import deque


def solve():
    import sys

    T = int(sys.stdin.readline())

    # 方向映射
    dirs = {'^': (-1, 0), 'v': (1, 0), '<': (0, -1), '>': (0, 1)}

    for case_num in range(1, T + 1):
        # 读取 N M
        line = sys.stdin.readline()
        while line.strip() == '':
            line = sys.stdin.readline()
        N, M = map(int, line.split())

        # 读取网格
        grid = []
        for _ in range(N):
            row = sys.stdin.readline().strip()
            # 确保长度足够
            while len(row) < M:
                row += sys.stdin.readline().strip()
            grid.append(list(row))

        # 概率矩阵，使用 Fraction 保证精确分数
        prob = [[Fraction(0) for _ in range(M)] for __ in range(N)]

        # 起点
        start = (0, 0)
        prob[0][0] = Fraction(1)

        # BFS 队列
        q = deque([start])

        # 记录哪些节点已经加入过队列（避免重复加入，但概率仍可累加）
        in_queue = [[False] * M for _ in range(N)]
        in_queue[0][0] = True

        # 收集的总概率
        total_collected = Fraction(0)

        while q:
            r, c = q.popleft()
            cell = grid[r][c]
            current_prob = prob[r][c]

            # 如果当前概率为 0，跳过
            if current_prob == 0:
                continue

            # 空 tile：不应该发生，但安全处理
            if cell == '.':
                continue

            # Destroy tile：物品被销毁，不继续传播
            if cell == 'X' or cell == '×':
                continue

            # Splitter tile
            if cell == 'S' or cell == 's':
                # 收集所有有效的邻居
                valid_neighbors = []

                for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                    nr, nc = r + dr, c + dc
                    if 0 <= nr < N and 0 <= nc < M:
                        neigh = grid[nr][nc]

                        # Destroy tile 是有效的
                        if neigh == 'X' or neigh == '×':
                            valid_neighbors.append((nr, nc))

                        # Conveyor tile：需要检查是否指向 splitter
                        elif neigh in '<>^v':
                            ndr, ndc = dirs[neigh]
                            # conveyor 指向的目标
                            target_r = nr + ndr
                            target_c = nc + ndc
                            # 如果 conveyor 指向 splitter，则无效
                            if not (target_r == r and target_c == c):
                                valid_neighbors.append((nr, nc))

                        # Splitter 相邻 splitter：题目保证不会发生，但如果有则忽略
                        # （什么都不做，不加入 valid）

                # 分流
                k = len(valid_neighbors)
                if k > 0:
                    share = current_prob / k
                    for nr, nc in valid_neighbors:
                        prob[nr][nc] += share
                        if not in_queue[nr][nc]:
                            in_queue[nr][nc] = True
                            q.append((nr, nc))

            # Conveyor tile
            elif cell in '<>^v':
                dr, dc = dirs[cell]
                nr, nc = r + dr, c + dc

                # 检查是否出界
                if 0 <= nr < N and 0 <= nc < M:
                    # 在网格内
                    prob[nr][nc] += current_prob
                    if not in_queue[nr][nc]:
                        in_queue[nr][nc] = True
                        q.append((nr, nc))
                else:
                    # 指向网格外 → 被收集
                    total_collected += current_prob

            # 其他字符（不应该出现）
            else:
                # 可能是数字或其他，忽略
                pass

        # 输出结果：最简分数
        p = total_collected.numerator
        q_val = total_collected.denominator

        # 如果概率为 0，输出 "0 1"
        if p == 0:
            q_val = 1

        print(f"{p} {q_val}")


if __name__ == "__main__":
    solve()