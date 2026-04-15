for _ in range(int(input())):
    lenofArr = int(input())
    arrInput = list(map(int, input().split()))
    mDElement = sorted(arrInput)[lenofArr//2]
    C1T = sum(abs(arrInput[i] - mDElement) for i in range(lenofArr))
    C2T = 0
    print(*[mDElement] * lenofArr) if C1T <= C2T else print(*arrInput)