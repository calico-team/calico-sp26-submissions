import sys

def main():
    input = sys.stdin.read().split('\n')
    idx = 0
    t = int(input[idx])
    idx += 1

    for random in range(t):
        a = input[idx]
        idx += 1
        b = input[idx]
        idx += 1
        result = list(a)

        j = 0
        for i in range(len(a)):
            if (j < len(b) and a[i] == b[j]):
                j += 1
            else:
                result[i] = '#'
        print(''.join(result))

main()