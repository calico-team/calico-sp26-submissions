def sum(list1,list2,i,test):
    sum = abs(test-list1[i+1])+abs(test-list1[i-1])+abs(test-list2[i])
    return sum

def solve(N, A):
    list = A
    for i in range(1,len(list)-1):
        if list[i-1] > list[i+1]:
            for j in range(list[i+1],list[i-1]+1):
                if sum(list,A,i,j) < sum(list,A,i,list[i]):
                    list[i] = j
        else:
            for j in range(list[i-1],list[i+1]+1):
                if sum(list,A,i,j) < sum(list,A,i,list[i]):
                    list[i] = j
    return list


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        print(' '.join(str(x) for x in result))


if __name__ == '__main__':
    main()
