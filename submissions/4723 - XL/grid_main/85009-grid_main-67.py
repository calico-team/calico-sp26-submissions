def main():
    import sys
    input = sys.stdin.read().split()
    ptr = 0
    t = int(input[ptr])
    ptr += 1
    for i in range(t):
        n = int(input[ptr])
        ptr += 1
        arr = []
        for j in range(n):
            arr.append(int(input[ptr]))
            ptr += 1
        ans = [0] * n
        for j in range(n):
            if j == 0 or j == n - 1:
                ans[j] = arr[j]
            elif arr[j] == ans[j-1]:
                ans[j] = arr[j]
            else:
                if arr[j+1] >= arr[j] and arr[j+1] >= ans[j-1]:
                    ans[j] = max(ans[j-1], arr[j])
                elif (arr[j+1] >= arr[j] and arr[j+1] <= ans[j-1]) or (arr[j+1] <= arr[j] and arr[j+1] >= ans[j-1]):
                    ans[j] = arr[j+1]
                else:
                    ans[j] = min(ans[j-1], arr[j])
        res = ' '.join(map(str, ans))
        print(res)

main()