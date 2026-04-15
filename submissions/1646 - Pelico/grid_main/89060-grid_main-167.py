
def main():
    a=int(input())
    b=list(input())
    for i in range(len(b)-1):
        diff+=abs(b[i]-b[i+1])
    return diff

if __name__ == '__main__':
    main()
