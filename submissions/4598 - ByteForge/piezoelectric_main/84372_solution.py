import sys

input = sys.stdin.readline

# this is easy 

#tum bi kro ge na 
def solve():
    L, W, E, R =map(int,input().split())
     
     
    pariiii= 2*(L+W)
    #iyses
    
    enriii=pariiii * R #hogia hal 
    
    lp=E//enriii #g hogia 
    
    print(lp)
    
def main():
    
    taniya=int(input())
    
    for __ in range (taniya):
        
        solve()
        
        
main()