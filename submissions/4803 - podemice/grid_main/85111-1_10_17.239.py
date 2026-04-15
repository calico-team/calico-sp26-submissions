def solve(K, heights):
    if (K == 3):
        return [heights[0], sorted(heights)[1], heights[2]]
    return heights

def main():
    T = int(input())
    for _ in range(T):
        K = int(input())
        heights = list(map(int, input().split(" ")))

        print(solve(K, heights))

main()
