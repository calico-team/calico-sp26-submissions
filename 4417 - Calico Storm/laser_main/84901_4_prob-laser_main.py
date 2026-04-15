T = int(input())

for _ in range(T):
    total_rocks, grid_width, grid_height, step_y, step_x = map(int, input().split())

    rock_positions = []
    for i in range(total_rocks):
        px, py = map(int, input().split())
        rock_positions.append((px, py))

    origin_x, origin_y = rock_positions[0]
    lazarbeam = {(px, py): idx for idx, (px, py) in enumerate(rock_positions)}

    beam_x, beam_y = origin_x, origin_y

    while True:
        beam_x = (beam_x + step_x) % grid_width
        beam_y = (beam_y + step_y) % grid_height

        if (beam_x, beam_y) in lazarbeam:
            print(lazarbeam[(beam_x, beam_y)])
            break

def read_your_input():
    return map(int, input().split())