def solve(K, heights):
    if (K == 3):
        return [heights[0], sorted(heights)[1], heights[2]]
    return heights

def main():
    T = int(input())
    for _ in range(T):
        K = int(input())
        heights = list(map(int, input().split(" ")))

        out = solve(K, heights)
        to_print = str(out[0])
        for i in range(1, len(out)):
            to_print += " " + str(out[i])
        print(to_print)
main()
