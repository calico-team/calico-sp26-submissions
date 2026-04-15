def solve(N, A):
    list = A
    for i in range(1,len(list)-1):
        if list[i-1] == list[i+1]:
            list[i] = list[i-1]
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
