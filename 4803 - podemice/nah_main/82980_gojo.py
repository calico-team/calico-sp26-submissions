def solve(num_curse, power, rev, k, curses):
    pow = power
    track = 0
    pow_arr = []
    for i in range(num_curse):
        pow_arr.append(pow)
        pow -= int(curses[i])
        if (pow < 0):
            return "nah i’d lose"
        track += 1
        if (track % int(k) == 0):
            pow += rev
    pow_arr.append(pow)
    return "nah i’d win"
    # YOUR CODE HERE

def main():
    T = int(input())
    for _ in range(T):
        gojo = input()
        N, P, R, K = gojo.split(" ")
        curses = input().split(" ")

        print(solve(int(N), int(P), int(R), int(K), curses))

main()
