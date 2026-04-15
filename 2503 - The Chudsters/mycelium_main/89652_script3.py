import time
def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    """
    Return the total number of tiles mycelium will ever occupy.

    X_G: x-coordinate of grass starting position
    Y_G: y-coordinate of grass starting position
    X_M: x-coordinate of mycelium starting position
    Y_M: y-coordinate of mycelium starting position
    """
    tick = 0
    grass=[[X_G,Y_G]]
    my = [[X_M,Y_M]]
    can_move = True
    amount = 0
    amount2 = 0
    sum = 0
    hi= amount
    while (can_move == True):
        ngrass = []
        nmy = []

        time.sleep(1)
        if tick%2==0 and tick != 0:
            for x in range(len(grass)-hi-1,len(grass)):
                if ([grass[x][0]-1,grass[x][1]] not in grass) and([grass[x][0]-1,grass[x][1]] not in my):
                    ngrass.append([grass[x][0]-1,grass[x][1]])
                    amount +=1
                if ([grass[x][0]+1,grass[x][1]] not in grass) and([grass[x][0]+1,grass[x][1]] not in my):
                    ngrass.append([grass[x][0]+1,grass[x][1]])
                    amount +=1
                if ([grass[x][0],grass[x][1]-1] not in grass) and([grass[x][0],grass[x][1]-1] not in my):
                    ngrass.append([grass[x][0],grass[x][1]-1])
                    amount +=1
                if ([grass[x][0],grass[x][1]+1] not in grass) and([grass[x][0],grass[x][1]+1] not in my):
                    ngrass.append([grass[x][0],grass[x][1]+1])
                    amount +=1
        if tick%7==0 and tick != 0:
            for y in range(len(my)-hi2-1,len(my)):
                if([my[y][0]-1,my[y][1]] not in my) and ([my[y][0]-1,my[y][1]] not in grass):
                    nmy.append([my[y][0]-1,my[y][1]])
                    amount2 += 1
                if([my[y][0]+1,my[y][1]] not in my) and ([my[y][0]+1,my[y][1]] not in grass):
                    nmy.append([my[y][0]+1,my[y][1]])
                    amount2 += 1
                if([my[y][0],my[y][1]-1] not in my) and ([my[y][0],my[y][1]-1] not in grass):
                    nmy.append([my[y][0],my[y][1]-1])
                    amount2 += 1
                if([my[y][0],my[y][1]+1] not in my) and ([my[y][0],my[y][1]+1] not in grass):
                    nmy.append([my[y][0],my[y][1]+1])
                    amount2 += 1
        for a in ngrass:
            grass.append(a)
        for b in nmy:
            my.append(b)
            if amount2 == 0:
                can_move = False
        sum += amount2
        hi = amount
        hi2 = amount2
        amount = 0
        amount2 = 0
        tick += 1

    # YOUR CODE HERE
    return sum


def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()
