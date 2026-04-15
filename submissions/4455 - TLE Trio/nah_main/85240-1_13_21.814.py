import sys
read = sys.stdin.readline

user_read = int(input())

for data in range(user_read):

    num , win , ratio , points = map(int, input().split())
    club = list(map(int, input().split()))
    
    Win = win
    lose = 0
    
    result = False
    
    for c in club:

        Win -= c
        
        if Win < 0:
            result = True
            break

        lose += 1

        if lose % points == 0:
            Win += ratio
    
    print("nah i'd win" if not result else "nah i'd lose")