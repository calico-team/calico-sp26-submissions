def solve():
    t = int(input().strip())
    for _ in range(t):
        n = int(input().strip())
        the_two_tower_heights = list(map(int, input().strip().split()))
        print(*the_two_tower_heights)

def read_your_input():
    solve()

if __name__ == "__main__":
    read_your_input()