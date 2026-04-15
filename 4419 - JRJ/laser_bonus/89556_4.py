import sys


def solve():
    data = sys.stdin.read().split()
    t = int(data[0])
    idx = 1
    out = []
    for _ in range(t):
        K = int(data[idx]);
        idx += 1
        N = int(data[idx]);
        idx += 1
        M = int(data[idx]);
        idx += 1
        P = int(data[idx]);
        idx += 1
        Q = int(data[idx]);
        idx += 1
        asteroids = []
        for i in range(K):
            x = int(data[idx]);
            idx += 1
            y = int(data[idx]);
            idx += 1
            asteroids.append((x, y))

        start_x, start_y = asteroids[0]
        lazarbeam = 0


        visited = {}
        cur_x, cur_y = start_x, start_y
        step = 0
        hit = -1
        while True:

            if step > 0:
                for i in range(K):
                    if asteroids[i] == (cur_x, cur_y):
                        hit = i
                        break
                if hit != -1:
                    break

            cur_x = (cur_x + Q) % N
            cur_y = (cur_y + P) % M
            step += 1

            if (cur_x, cur_y) == (start_x, start_y):

                hit = 0
                break

            if (cur_x, cur_y) in visited:

                hit = 0
                break
            visited[(cur_x, cur_y)] = step
        out.append(str(hit))
    sys.stdout.write("\n".join(out))


if __name__ == "__main__":
    solve()