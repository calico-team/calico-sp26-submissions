import sys

def main():
    input = sys.stdin.read().splitlines()
    ptr = 0
    T = int(input[ptr])
    ptr += 1
    for _ in range(T):
        N = int(input[ptr])
        ptr += 1
        s1 = []
        for _ in range(N):
            s1.append(input[ptr].strip())
            ptr += 1
        s2 = []
        for _ in range(N):
            s2.append(input[ptr].strip())
            ptr += 1
        max_vol = 0
        min_vol = 0
        for x in range(N):
            cy = s1[x].count('#')
            cz = s2[x].count('#')
            max_vol += cy * cz
            min_vol += max(cy, cz)
        print(max_vol, min_vol)

if __name__ == "__main__":
    main()
