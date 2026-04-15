def main():
    times = input()
    results = []
    for i in range(int(times)):
        ints = input().split(" ")
        numcurses = int(ints[0]) # 3
        gojopower = int(ints[1]) # 20
        powerreverserestore = int(ints[2]) # 50
        cursesfornextreverse = int(ints[3]) # 3
        powerlevelspercurse = input().split(" ")
        totalcursepower = 0 #30
        for curse in powerlevelspercurse:
            totalcursepower += int(curse)
        
        # if gojopower > totalcursepower:
        #     # print("nah i’d win")
        #     results.append("nah i'd win")

        numsdefeated = 0
        for i in range(int(numcurses)):
            gojopower -= int(powerlevelspercurse[i])
            if gojopower < 0:
                # print("nah i’d lose")
                results.append("nah i'd lose")
                return
            numsdefeated += 1
            if numsdefeated % cursesfornextreverse == 0:
                gojopower += powerreverserestore
        results.append("nah i'd win")
    for result in results:
        print(result)
main()