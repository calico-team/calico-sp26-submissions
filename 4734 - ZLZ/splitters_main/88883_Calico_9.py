# Watch my 9 years of Create Mod experience cook
from math import lcm, gcd
from copy import deepcopy
import sys


class Fraction():
    def __init__(self, numerator, denominator):
        self.numerator = numerator
        self.denominator = denominator

    def __add__(self, other):
        lcm_of_denominators = lcm(self.denominator, other.denominator)
        numerator = self.numerator * lcm_of_denominators // self.denominator + other.numerator * lcm_of_denominators // other.denominator
        return Fraction(numerator, lcm_of_denominators)

    def __mul__(self, other):
        return Fraction(self.numerator * other.numerator, self.denominator * other.denominator)

    def __str__(self):
        return f"{self.numerator} / {self.denominator}"

    def simplify(self):
        common_factor_of_numerator_and_denominator = gcd(self.numerator, self.denominator)
        self.numerator //= common_factor_of_numerator_and_denominator
        self.denominator //= common_factor_of_numerator_and_denominator


items_that_leave = Fraction(0, 1)


class Conveyor:
    def __init__(self, grid_x, grid_y, char_used_to_generate):
        if char_used_to_generate == ">":
            self.direction = "right"
        elif char_used_to_generate == "<":
            self.direction = "left"
        elif char_used_to_generate == "v":
            self.direction = "down"
        elif char_used_to_generate == "^":
            self.direction = "up"
        else:
            raise Exception("Excuse me what the actual fuck")
        self.fraction_of_items_that_enter = Fraction(0, 1)
        self.grid_x = grid_x
        self.grid_y = grid_y

    def receive(self, fraction_of_items_that_enter_from_another_element):
        self.fraction_of_items_that_enter += fraction_of_items_that_enter_from_another_element

    def give_to_another_conveyor(self, world_grid, width, height):
        if self.fraction_of_items_that_enter.numerator == 0:
            return
        global items_that_leave
        if self.direction == "right":
            offset = (0, 1)
        elif self.direction == "left":
            offset = (0, -1)
        elif self.direction == "down":
            offset = (1, 0)
        elif self.direction == "up":
            offset = (-1, 0)
        else:
            raise Exception("What? I thought I caught this error")
        y_offset, x_offset = offset
        x_coordinate = x_offset + self.grid_x
        y_coordinate = y_offset + self.grid_y
        if x_coordinate < 0 or x_coordinate >= width:
            # print(f"Exited the system with {self.fraction_of_items_that_enter}")
            items_that_leave += self.fraction_of_items_that_enter
            world_grid[self.grid_y][self.grid_x].fraction_of_items_that_enter = Fraction(0, 1)
            return
        if y_coordinate < 0 or y_coordinate >= height:
            items_that_leave += self.fraction_of_items_that_enter
            # print(f"Exited the system with {self.fraction_of_items_that_enter}")
            world_grid[self.grid_y][self.grid_x].fraction_of_items_that_enter = Fraction(0, 1)
            return
        cell = world_grid[y_coordinate][x_coordinate]
        # print(f"Write to [{y_coordinate}][{x_coordinate}] from cell [{self.grid_y}][{self.grid_x}]")
        cell.receive(self.fraction_of_items_that_enter)
        world_grid[self.grid_y][self.grid_x].fraction_of_items_that_enter = Fraction(0, 1)


class Destroyer:
    def __init__(self, grid_x, grid_y, char_used_to_generate):
        if not char_used_to_generate == "X":
            raise Exception("What? I thought I caught this error")
        self.grid_x = grid_x
        self.grid_y = grid_y
        self.fraction_of_items_that_enter = Fraction(0, 1)

    def receive(self, fraction_of_items_that_enter_from_another_element):
        self.fraction_of_items_that_enter = Fraction(0, 1)

    def give_to_another_conveyor(self, world_grid, width, height):
        pass


class Splitter:
    def __init__(self, grid_x, grid_y, char_used_to_generate):
        if not char_used_to_generate == "S":
            raise Exception("The fuck?")
        self.fraction_of_items_that_enter = Fraction(0, 1)
        self.grid_x = grid_x
        self.grid_y = grid_y

    def receive(self, fraction_of_items_that_enter_from_another_element):
        self.fraction_of_items_that_enter += fraction_of_items_that_enter_from_another_element

    def give_to_another_conveyor(self, world_grid, width, height):
        if self.fraction_of_items_that_enter.numerator == 0:
            return
        offsets = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        cells_to_receive = []
        for offset in offsets:
            x_offset, y_offset = offset
            x_coordinate = x_offset + self.grid_x
            y_coordinate = y_offset + self.grid_y
            if width <= x_coordinate < 0 or height <= y_coordinate < 0:
                continue  # the conveyor will be outside the map
            cell = world_grid[y_coordinate][x_coordinate]
            if type(cell) is Conveyor:
                if offset == (0, 1):
                    direction_conveyor_shouldnt_have = "up"
                elif offset == (1, 0):
                    direction_conveyor_shouldnt_have = "left"
                elif offset == (-1, 0):
                    direction_conveyor_shouldnt_have = "right"
                elif offset == (0, -1):
                    direction_conveyor_shouldnt_have = "down"
                else:
                    raise Exception("Big Yahu Please Help me out")
                # print(cell.direction, offset)
                if cell.direction != direction_conveyor_shouldnt_have:
                    cells_to_receive.append(cell)
            elif type(cell) == Destroyer:
                cells_to_receive.append(cell)
            elif type(cell) == Splitter:
                raise Exception("No adjacent splitters, remember?")
        items_given_to_each_element = self.fraction_of_items_that_enter * Fraction(1, len(cells_to_receive))
        for cell in cells_to_receive:
            cell.receive(items_given_to_each_element)
        world_grid[self.grid_y][self.grid_x].fraction_of_items_that_enter = Fraction(0, 1)


class Air:
    def __init__(self, grid_x, grid_y, char_used_to_generate):
        if not char_used_to_generate == ".":
            raise Exception("Genuinely what the fuck")
        self.grid_x = grid_x
        self.grid_y = grid_y
        self.fraction_of_items_that_enter = Fraction(0, 1)

    def receive(self, fraction_of_items_that_enter_from_another_element):
        pass

    def give_to_another_conveyor(self, world_grid, width, height):
        pass


world_1 = "v.>>>>v.^.\nv.^...v.^.\n>>S>S>>>S.\n..X.v...v.\n....>>>>X.\n.........."
world_2 = "vX.\n>SX\n.X."


def is_empty(world_grid):
    for row in world_grid:
        for cell in row:
            if cell.fraction_of_items_that_enter.numerator != 0:
                return False
    return True


def solve_1_test_case(world):
    width = len(world.split('\n')[0])
    height = len(world.split('\n'))
    world_grid = [[Air(i, j, ".") for j in range(width)] for i in range(height)]
    for i, line in enumerate(world.split("\n")):
        for j, char in enumerate(line):
            if char == ">":
                world_grid[i][j] = Conveyor(j, i, char)
            elif char == "<":
                world_grid[i][j] = Conveyor(j, i, char)
            elif char == "^":
                world_grid[i][j] = Conveyor(j, i, char)
            elif char == "v":
                world_grid[i][j] = Conveyor(j, i, char)
            elif char == "X":
                world_grid[i][j] = Destroyer(j, i, char)
            elif char == ".":
                world_grid[i][j] = Air(j, i, char)
            elif char == "S":
                world_grid[i][j] = Splitter(j, i, char)
            else:
                raise Exception("The fuck")
    world_grid[0][0].receive(Fraction(1, 1))  # seed the shit
    def print_world_grid(world_grid):
        ret = ""
        for row in range(len(world_grid)):
            for col in range(len(world_grid[row])):
                if type(world_grid[row][col]) in [Conveyor, Splitter, Destroyer]:
                    fraction = world_grid[row][col].fraction_of_items_that_enter
                    length_of_str_fraction = len(str(fraction))
                    ret += str(fraction) + " " * (8 - length_of_str_fraction)
                else:
                    ret += str("0 (air) ")
            ret += "\n"
        print(ret)
    # print_world_grid(world_grid)
    copied_world_grid = deepcopy(world_grid)
    for row in world_grid:
        for cell in row:
            cell.give_to_another_conveyor(copied_world_grid, width, height)
    # print_world_grid(copied_world_grid)
    new_copied_world_grid = deepcopy(copied_world_grid)
    for row in copied_world_grid:
        for cell in row:
            cell.give_to_another_conveyor(new_copied_world_grid, width, height)
    # print_world_grid(new_copied_world_grid)
    # for i in range(width * height):
    while not is_empty(new_copied_world_grid):
        copied_world_grid = new_copied_world_grid
        new_copied_world_grid = deepcopy(copied_world_grid)
        for row in copied_world_grid:
            for cell in row:
                cell.give_to_another_conveyor(new_copied_world_grid, width, height)
        # print_world_grid(new_copied_world_grid)
    items_that_leave.simplify()
    print(items_that_leave.numerator, items_that_leave.denominator)
    items_that_leave.denominator = 1
    items_that_leave.numerator = 0


def solve():
    input = sys.stdin.read
    data = input().splitlines()

    t = int(data[0])
    ret = []
    temp = [0, 0, ""]
    # print(data[1:], t)
    for line in data[1:]:
        if " " in line:
            ret.append(temp)
            temp = [0, 0, ""]
            width = int(line.split(" ")[1])
            height = int(line.split(" ")[0])
            temp[0] = width
            temp[1] = height
        else:
            temp[2] += line + "\n"
    ret.append(temp)
    ret = ret[1:]
    # print(ret)
    for width, height, world in ret:
        world = world[:-1]  # get rid of trailing \n
        solve_1_test_case(world)


if __name__ == "__main__":
    solve()
    # solve_1_test_case(world_1)
