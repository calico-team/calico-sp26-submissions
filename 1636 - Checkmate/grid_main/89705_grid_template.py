def solve(N, A):
    """
    Find an array B of N integers representing the filled-in second row,
    chosen to minimize the sum of absolute differences of adjacent
    numbers on the grid.

    N: the number of columns in the 2 x N grid
    A: list of N integers giving the first row of the grid
    """
    # YOUR CODE HERE

    # 3 case, copy row, do 1 or min, average

    a_total = 0
    for i in range(1,N):
        a_total = A[i] + A[i-1]

    # [6, 2, 4, 1]
    # [6, 2, 4, 1]
    # case1: copy row
    c1_row = A
    c1x_sum = sum(A)
    c1y_sum = 0
    c1_total = c1x_sum + c1y_sum
    # print("c1row, total", c1_row, c1_total)



    # case 2, use min ele
    # [6,2,4,1]
    # [1,1,1,1]
    min_ele = min(A)
    row2 = [min_ele for _ in range(N)]
    c2x_sum = 0
    c2y_sum = 0
    for i in range(N):
        diff = abs(row2[i] - A[i])
        c2y_sum += diff
    c2_total = c2x_sum + c2y_sum

    # case3: average
    # [6,2,4,1]
    # [3,3,3,3]
    average = sum(A) // N
    c3x_sum = 0
    c3y_sum = 0
    # print("avg", average)
    for i in range(N):
        diff = abs(average - A[i])
        c3y_sum += diff
    c3_total = c3x_sum + c3y_sum

    # print(c1_total, c2_total, c3_total)

    if c1_total < c2_total and c1_total < c3_total:       
        # print("returning A", A) 
        return A
    elif c2_total < c1_total and c2_total < c3_total:
        # print("return min ele", min_ele)
        return [min_ele] * N
    else:
        # print("retuungin average", average)
        return [average] * N

 


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        print(' '.join(str(x) for x in result))


if __name__ == '__main__':
    main()
