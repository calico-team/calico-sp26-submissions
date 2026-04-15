import itertools

def solve(N, A:list):
    """
    Find an array B of N integers representing the filled-in second row,
    chosen to minimize the sum of absolute differences of adjacent
    numbers on the grid.

    N: the number of columns in the 2 x N grid
    A: list of N integers giving the first row of the grid
    """
    
    # YOUR CODE HERE
    bestbottomtower=A.copy()
    
    lastdif=0
    for i in range(1, N):
        bottowN=bestbottomtower[i]
        prevbotttowN=bestbottomtower[i-1]
        AN=A[i]
        currentdif=prevbotttowN-bottowN
        
        samesign= currentdif*lastdif>0
        if samesign:
            smaller = min(lastdif,currentdif,key=abs)
            bestbottomtower[i-1]-=smaller
            prevbotttowN=bestbottomtower[i-1]
            pass
        lastdif=bottowN-prevbotttowN
        
    # bestscore=getscore(bestbottomtower,A)#float("inf")
    
    # nums=set(A)
    # combos = list(itertools.product(nums, repeat=N))
    # # print(combos)
    # for newtower in combos:
    #     # bla bla gen lists
    #     score = getscore(newtower,A)
    #     # print(score,newtower)
    #     if bestscore>score:
    #         bestscore=score
    #         bestbottomtower=newtower
        
    
    return bestbottomtower#, bestscore
    # return [0 for _ in range(N)]

def getscore(A:list,OG):
    score=0
    previousn=A[0]
    for i,n in enumerate(A):
        score+=abs(previousn-n)
        score+=abs(OG[i]-n)
        previousn=n
    return score
        

def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        
        print(' '.join(str(x) for x in result))


if __name__ == '__main__':
    main()
