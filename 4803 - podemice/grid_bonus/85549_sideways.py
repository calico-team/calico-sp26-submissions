def solve(K, heights):
    if (K < 3):
        return heights
    
    out = [heights[0]]
    last = heights[len(heights) - 1]
    for i in range(1, len(heights)):
        out.append(sorted([out[i - 1], heights[i], last])[1])
    return out

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
