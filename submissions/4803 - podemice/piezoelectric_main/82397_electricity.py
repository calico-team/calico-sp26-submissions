def solve(L, W, E, R):
    return int(int(E) / ((2 * int(L) + 2 * int(W)) * int(R)))
    # YOUR CODE HERE

def main():
    T = int(input())
    for _ in range(T):
        n = input()
        L, W, E, R = n.split(" ")
        print(solve(L, W, E, R))

main()
