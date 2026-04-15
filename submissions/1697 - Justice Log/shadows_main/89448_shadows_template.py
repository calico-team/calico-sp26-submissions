def solve(N: int, S1: list[str], S2: list[str]) -> tuple[int, int]:
    max_volume = 0
    min_volume = 0
    
    for i in range(N): 

        shadow1 = S1[i].count('#')
        shadow2 = S2[i].count('#')   


        max_volume += shadow1 * shadow2   

        min_volume += max(shadow1, shadow2)
    return max_volume, min_volume 


def main():
    T = int(input()) 
    for _ in range(T):
        N = int(input())
        S1 = [input() for _ in range(N)] 
        S2 = [input() for _ in range(N)]
        print(*solve(N, S1, S2))


if __name__ == '__main__':
    main()