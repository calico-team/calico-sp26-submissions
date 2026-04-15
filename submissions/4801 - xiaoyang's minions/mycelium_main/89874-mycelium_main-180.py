def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    """
    Return the total number of tiles mycelium will ever occupy.

    X_G: x-coordinate of grass starting position
    Y_G: y-coordinate of grass starting position
    X_M: x-coordinate of mycelium starting position
    Y_M: y-coordinate of mycelium starting position
    """
    t = 1
    grass = [[X_G, Y_G]]
    mycelium = [[X_M, Y_M]]
    mycelium_state = True
    while mycelium_state == True:
        print(f"t = {t}")

        if t % 2 == 0:
            n_grass = []
            for block in grass:
                new_blocks = [[block[0]+1, block[1]], [block[0]-1, block[1]], [block[0], block[1]+1], [block[0], block[1]-1]]
                new_blocks_success = []
                for new_block in new_blocks:
                    if (new_block not in grass) and (new_block not in mycelium):
                        new_blocks_success.append(new_block)
                for blockt in new_blocks_success:
                    n_grass.append(blockt)
            grass.extend(n_grass)

        if t % 7 == 0:
            n_mycelium = []
            for block in mycelium:
                added = False
                new_blocks_2 = [[block[0]+1, block[1]], [block[0]-1, block[1]], [block[0], block[1]+1], [block[0], block[1]-1]]
                new_blocks_success = []
                for new_block in new_blocks_2:
                    if (new_block not in grass) and (new_block not in mycelium):
                            new_blocks_success.append(new_block)
                            added = True
                for block in new_blocks_success:
                    n_mycelium.append(block)
            if len(n_mycelium) == 0:
                return(len(mycelium))
            #print(n_mycelium)
            mycelium.extend(n_mycelium)
        #print(mycelium)
        #print(grass)
        t+=1
def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()