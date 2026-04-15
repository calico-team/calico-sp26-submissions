#include <iostream>
using namespace std;
int t, a[1005][1005];
int main()
{
	a[1][1]=a[2][4]=a[3][2]=a[4][5]=a[5][3]=2;
	a[1][2]=a[2][5]=a[3][3]=a[4][1]=a[5][4]=4;
	a[1][3]=a[2][1]=a[3][4]=a[4][2]=a[5][5]=0;
	a[1][4]=a[2][2]=a[3][5]=a[4][3]=a[5][1]=1;
	a[1][5]=a[2][3]=a[3][1]=a[4][4]=a[5][2]=3;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++)
				cout << a[i % 5 + 1][j % 5 + 1] << ' ';
			cout << '\n';
		}
    }
    return 0;
}