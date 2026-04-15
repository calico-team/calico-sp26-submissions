# def solve(L, W, E, R):
#     """
#     Return the number of laps needed to charge the car (rounded up)

#     L: Length of car
#     W: Width of car
#     E: Amount of electricity to generate
#     R: Electricity generated per unit distance
#     """

#     # YOUR CODE HERE
#     perimeter = (2 * L) + (2 * W)
#     steps_into_perimeter = perimeter * R

#     ans = 1
#     while steps_into_perimeter < E:
#         ans += 1
#         steps_into_perimeter += perimeter * R

#     return ans


# def main():
#     T = int(input())
#     for _ in range(T):
#         temp = input().split()
#         L = int(temp[0])
#         W = int(temp[1])
#         E = int(temp[2])
#         R = int(temp[3])

#         print(solve(L, W, E, R))


# if __name__ == "__main__":
#     main()
    
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

    
    count=0
   
    for i in E:
        
        if count>=K:
            P = P+R
            count = count - K
            
        
        if(P<i):
            return "nah i'd lose" 
        P-=i
        count+=1
        
        
     
    
    return "nah i'd win"  
            
        


def main() -> None:
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))


if __name__ == "__main__":
    main()
