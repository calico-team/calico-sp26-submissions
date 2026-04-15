def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    dx = X_G - X_M
    dy = Y_G - Y_M
    
    ans = 0

    # We iterate over u (x direction), and compute valid v range
    LIMIT = 10**6  # large enough, but we break early

    for u in range(-LIMIT, LIMIT + 1):
        # We solve inequality for v
        
        # 7(|u| + |v|) < 2(|u - dx| + |v - dy|)
        # Fix u → solve for v
        
        # Binary search range of v
        lo, hi = -LIMIT, LIMIT
        
        def good(v):
            return 7*(abs(u) + abs(v)) < 2*(abs(u - dx) + abs(v - dy))
        
        # find left boundary
        l, r = lo, hi
        left = None
        while l <= r:
            mid = (l + r) // 2
            if good(mid):
                left = mid
                r = mid - 1
            else:
                l = mid + 1
        
        if left is None:
            continue
        
        # find right boundary
        l, r = left, hi
        right = left
        while l <= r:
            mid = (l + r) // 2
            if good(mid):
                right = mid
                l = mid + 1
            else:
                r = mid - 1
        
        ans += (right - left + 1)
        
        # optimization: stop when no valid v exists and we're far
        if left is None and abs(u) > max(abs(dx), abs(dy)) * 10:
            break

    return ans


def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()