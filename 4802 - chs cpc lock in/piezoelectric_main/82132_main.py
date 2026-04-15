for tc in range(int(input())):
    l,w,e,r = map(int, input().split())
    print( e // (r*2*(l+w)))
