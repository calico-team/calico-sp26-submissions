def main():
    n = int(input())
    a = list(map(int,input().split()))
    best_num = 10**9
    for i in range(2**(n-1)):
        num = 0
        b = [a[0]]
        seed = bin(i)[2:]
        if (len(seed)<(n-1)):
            seed = '0'*(n-1-len(seed)) + seed
        for j in range(len(seed)):
            if seed[j] == '1':
                b.append(a[j+1])
                num += abs(b[-1]-b[-2])
            else:
                b.append(b[-1])
                num += abs(b[-1]-a[j+1])
        if num < best_num:
            best_num = num
            best_b = b
    for k in best_b:
        print(k,end=' ')

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        main()
        print()