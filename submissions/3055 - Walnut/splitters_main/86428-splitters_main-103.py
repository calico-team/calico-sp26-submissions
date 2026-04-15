moves = {
    '^': (-1, 0),
    'v': (1, 0),
    '<': (0, -1),
    '>': (0, 1)
}
def gcd(first, second):
    while second:
        first, second = second, first % second
    return first
def reduce(top, bottom):
    if top == 0:
        return (0, 1)
    part = gcd(abs(top), abs(bottom))
    top //= part
    bottom //= part
    if bottom < 0:
        top = -top
        bottom = -bottom
    return (top, bottom)
def add(first, second):
    atop, abottom = first
    btop, bbottom = second
    return reduce(atop * bbottom + btop * abottom, abottom * bbottom)
def divide(value, count):
    top, bottom = value
    return reduce(top, bottom * count)
tests = int(input())
for i in range(tests):
    rows, columns = map(int, input().split())
    board = [input().strip() for _ in range(rows)]
    seen = {}
    def walk(row, column):
        if (row, column) in seen:
            return seen[(row, column)]
        tile = board[row][column]
        if tile in 'xX':
            value = (0, 1)
        elif tile in moves:
            rise, run = moves[tile]
            nextrow = row + rise
            nextcolumn = column + run
            if 0 <= nextrow < rows and 0 <= nextcolumn < columns:
                value = walk(nextrow, nextcolumn)
            else:
                value = (1, 1)
        else:
            total = (0, 1)
            count = 0
            for rise, run in ((-1, 0), (1, 0), (0, -1), (0, 1)):
                nextrow = row + rise
                nextcolumn = column + run
                if not (0 <= nextrow < rows and 0 <= nextcolumn < columns):
                    continue
                nexttile = board[nextrow][nextcolumn]
                if nexttile in 'xX':
                    total = add(total, walk(nextrow, nextcolumn))
                    count += 1
                elif nexttile in moves:
                    backrow, backcolumn = moves[nexttile]
                    if nextrow + backrow == row and nextcolumn + backcolumn == column:
                        continue
                    total = add(total, walk(nextrow, nextcolumn))
                    count += 1
            value = divide(total, count)
        seen[(row, column)] = value
        return value
    top, bottom = walk(0, 0)
    print(top, bottom)