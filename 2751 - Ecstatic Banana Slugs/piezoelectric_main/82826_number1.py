from collections import deque
import sys
import os
if sys.gettrace() or os.getenv("TERM_PROGRAM") == "vscode":
    sys.stdin = open('/home/berti/spr2025calico/competeioncalico/testfilenumber1', "r")
def main(height: int, width:int,electricty_needed: int, how_much_is_generated:int):
    perimeter = height*2+width*2
    return electricty_needed//(perimeter*how_much_is_generated)
num_times= int(input())
# print (num_times)
for i in range(num_times):
    lol = input()
    l = lol.split()
    height = int(l[0])
    width = int(l[1])
    electricity = int(l[2])
    howmuchisgenerated = int(l[3]) 
    print(int(main(height,width,electricity,howmuchisgenerated)))    
