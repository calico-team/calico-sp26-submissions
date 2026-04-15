T = int(input())

for _ in range(T):
    N = int(input())#容器尺寸，每面墙有多少行
    leftWall = [input() for _ in range(N)]
    rightWall = [input() for _ in range(N)]
    maxi = 0
    mini = 0
    for i in range(N):
        leftShade = leftWall[i].count('#')
        rightShade = rightWall[i].count('#')
        maxi += leftShade * rightShade
        mini += max(leftShade, rightShade)

    print(f"{maxi} {mini}")