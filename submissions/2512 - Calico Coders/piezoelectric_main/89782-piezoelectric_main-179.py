
import sys
read = sys.stdin.readline

for _ in range(int(read())):
    car_len, car_wid, need, gain = map(int, read().split())
    
    walk = 2 * (car_len + car_wid)
    charge = walk * gain
    rounds = need // charge
    
    print(rounds)