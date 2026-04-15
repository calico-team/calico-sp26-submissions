def solve(a, b):
    i=0
    result=[]
    for chr in a:
        if i <len(b) and chr== b[i]:
            result.append(chr)
            i += 1
        else:
            result.append('#')
    return ''.join(result)
def main():
    T=int(input().strip())
    for _ in range(T): 
        A =input().strip()
        B=input().strip()
        ans= solve(A,B)
        print(ans)
#def read_input():
 #   main()

if __name__ =="__main__":
    main()