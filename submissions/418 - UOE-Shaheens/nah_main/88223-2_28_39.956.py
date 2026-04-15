def solve(N: int, P: int, R: int, K: int, E: list[int]) -> str:
    """
    Output whether Gojo will win the fight.

    N: Number of curses
    P: Gojo's starting power
    R: Amount of power Gojo can restore with Reverse Cursed Technique
    K: The cooldown of Reverse Cursed Technique
    E: List of power levels of curses
    """
    # YOUR CODE HERE
    temp = [E[0]]
    if K > N:
        return "nah i’d win"
    sum_of_power_levels = sum(E)
    if P >= sum_of_power_levels:
        return "nah i’d win"
    
    for i in range(1, N):
        temp.append(temp[i-1] + E[i])
    index = K-1
    prev_value = 0
    while(P > 0 and index < len(temp)):
        print(f"Index: {index}, Value: {temp[index]}")
        if (temp[index] - prev_value) > P:
            return "nah i’d lose"
        elif (temp[index] - prev_value) <= P:
            P -= (temp[index] - prev_value)
        prev_value = temp[index]
        index += K
        P += R
    if K % 2== 0 and N % 2 != 0:
        if P > temp[-1] - temp[index-K]:
            return "nah i’d win"
        else:
            return "nah i’d lose"
    if P > 0:
        return "nah i’d win"
    


def main() -> None:
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))


if __name__ == "__main__":
    main()
