def piezoelectricity(L,W,E,R):
    Perimeter=2*(L+W)
    Electricty_pr_lap=Perimeter*R
    no_lap=E//Electricty_pr_lap
    return no_lap
test_data=input()
for _ in range(int(test_data)):
    L,W,E,R=map(int, input().split())
    result=piezoelectricity(L,W,E,R)
    print(result)
