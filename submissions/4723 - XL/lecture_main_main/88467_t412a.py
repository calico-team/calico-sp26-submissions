def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    idx = 0
    T = int(data[idx])
    idx += 1
    for _ in range(T):
        N = int(data[idx])
        M = int(data[idx+1])
        K = int(data[idx+2])
        idx +=3
        seats = []
        for i in range(N):
            line = data[idx]
            idx +=1
            for j in range(M):
                if line[j] == '-':
                    seats.append((i,j))
        low = 0
        high = N + M
        bestD = N + M
        while low <= high:
            mid = (low + high) // 2
            ok = False
            for i in range(len(seats)):
                chosen = [seats[i]]
                for j in range(i+1, len(seats)):
                    p = seats[j]
                    valid = True
                    for c in chosen:
                        d = abs(p[0]-c[0]) + abs(p[1]-c[1])
                        if d > mid:
                            valid = False
                            break
                    if valid:
                        chosen.append(p)
                        if len(chosen) == K:
                            ok = True
                            break
                if ok:
                    break
            if ok:
                bestD = mid
                high = mid -1
            else:
                low = mid +1
        ans = []
        for p in seats:
            if len(ans) == K:
                break
            valid = True
            for c in ans:
                d = abs(p[0]-c[0]) + abs(p[1]-c[1])
                if d > bestD:
                    valid = False
                    break
            if valid:
                ans.append(p)
        for x,y in ans:
            print(x,y)
if __name__ == "__main__":
    main()