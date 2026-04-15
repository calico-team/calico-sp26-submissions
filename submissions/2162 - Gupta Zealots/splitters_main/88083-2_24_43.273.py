def solve(N, M, factory):
    """
    Simulate the factory and return the final output as the fraction P / Q.

    N: number of rows in the factory grid
    M: number of columns in the factory grid
    factory: list of N strings of length M, each character one of '^<>vSX.'
    """
    # YOUR CODE HERE
    return simplify(solveRecursive(N,M,factory,0,0))

def solveRecursive(N,M, factory, i, j):
    while True:
        if(factory[i][j] == 'S'):

            probabilitys = []
            if(factory[i-1][j] != '.' and factory[i-1][j] != 'v'):
                probabilitys.append(solveRecursive(N,M,factory,i-1,j))
            if(factory[i+1][j] != '.' and factory[i+1][j] != '^'):
                probabilitys.append(solveRecursive(N,M,factory,i+1,j))
            if(factory[i][j-1] != '.' and factory[i][j-1] != '>'):
                probabilitys.append(solveRecursive(N,M,factory,i,j-1))
            if(factory[i][j+1] != '.' and factory[i][j+1] != '<'):
                probabilitys.append(solveRecursive(N,M,factory,i,j+1))
            
            return average(probabilitys)

        elif(factory[i][j] == 'X'):
            return [0,1]
        elif(factory[i][j] == '^'):
            i -= 1
        elif(factory[i][j] == 'v'):
            i += 1
        elif(factory[i][j] == '>'):
            j += 1
        elif(factory[i][j] == '<'):
            j -= 1
        
        if(i < 0 or i >= N or j < 0 or j >= M):
            return [1,1]

def average(probabilitys):
    a = 0
    b = 1
    for probability in probabilitys:
        a = a * probability[1] + b * probability[0]
        b *= probability[1]
    
    b *= len(probabilitys)
    return [a,b]

def simplify(probability):

    if(probability[0] == 0):
        return [0,1]

    a = probability[0]
    b = probability[1]
    for i in range(2, min(a,b)+1):
        while(a % i == 0 and b % i == 0):
            a /= i
            b /= i
    
    a = int(a)
    b = int(b)
    return [a,b]

def main():
    T = int(input())
    for _ in range(T):
        N, M = map(int, input().split())
        factory = [input() for _ in range(N)]
        P, Q = solve(N, M, factory)
        print(P, Q)


if __name__ == '__main__':
    main()
