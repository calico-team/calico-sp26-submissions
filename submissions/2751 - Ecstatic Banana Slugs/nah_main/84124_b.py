import sys
if sys.gettrace():
    sys.stdout=open('nahtest.test')
def solve(num_curses,power,reversed_curse,delay,curses):
    cur_delay=delay
    cur_power=power
    for i in range(num_curses):
        
        cur_power-=curses[i]
        if cur_power<0:
            return "nah i'd lose"
        cur_delay-=1
        if cur_delay==0:
            cur_delay=delay
            cur_power+=reversed_curse
        


    return "nah i'd win"
problems = int(input())

for i in range(problems):
    data=input().split()
    num_curses=int(data[0])
    power=int(data[1])
    reversed_curse=int(data[2])
    delay=int(data[3])
    strcurses=input().split()
    curses=[]
    for j in range (num_curses):
        curses.append(int(strcurses[j]))


    print(solve(num_curses,power,reversed_curse,delay,curses))