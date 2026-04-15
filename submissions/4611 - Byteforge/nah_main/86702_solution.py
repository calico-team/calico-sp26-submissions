import sys
input= sys.stdin.readline

def solve():
    
    N, P , R, K = map(int,input().split())
    jajja=list(map(int,input().split()))

    kaaa= P
    
    loser= 0
     
     
    for alki in jajja:
        kaaa-= alki
        if kaaa < 0 :
            print("nah i'd lose")
            return
        loser+=1
        if loser % K ==0: 
            kaaa +=R
            
        
        #jia
    print("nah i'd win")
    
def main():
    #kos
    kaka= int(input())
    #kaaa
    for _ in range(kaka):
        solve()
        
main()
            
    
