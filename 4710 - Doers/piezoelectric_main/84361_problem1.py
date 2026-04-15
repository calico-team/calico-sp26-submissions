t = int(input())

for _ in range(t):
    length, width, energy, cost = map(int, input().split())
    lap = 2 * (length + width)
    steps = energy // cost
    rounds = steps // lap
    print(rounds)

def get():
    return input()