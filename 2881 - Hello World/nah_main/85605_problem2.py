def get_input():
    test_cases = int(input())
    for _ in range(test_cases):
        number_of_curses, current_power, power_restore, can_use_after = map(int, input().split())
        curse_powers = list(map(int, input().split()))
        times_used = 0
        defeated_curses = 0
        won = True
        for curse_power in curse_powers:
            available_uses = defeated_curses // can_use_after - times_used
            while current_power < curse_power and available_uses > 0:
                current_power += power_restore
                times_used += 1
                available_uses -= 1
            if current_power < curse_power:
                won = False
                break
            current_power -= curse_power
            defeated_curses += 1
        if won:
            print("nah i'd win")
        else:
            print("nah i'd lose")
def read_your_input():
    get_input()
read_your_input()