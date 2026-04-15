def main():
    times = input()
    for i in range(int(times)):
        ints = input().split(" ")
        numcurses = int(ints[0])
        gojopower = int(ints[1])
        powerreverserestore = int(ints[2])
        cursesfornextreverse = int(ints[3])
        powerlevelspercurse = input().split(" ")
        totalcursepower = 0
        for curse in powerlevelspercurse:
            totalcursepower += int(curse)
        
        if gojopower > totalcursepower:
            print("nah i’d win")

        numsdefeated = 0
        for i in range(int(numcurses)):
            gojopower -= int(powerlevelspercurse[i])
            if gojopower < 0:
                print("nah i’d lose")
                return
            numsdefeated += 1
            if numsdefeated % cursesfornextreverse == 0:
                gojopower += powerreverserestore
    print("nah i’d win")
main()