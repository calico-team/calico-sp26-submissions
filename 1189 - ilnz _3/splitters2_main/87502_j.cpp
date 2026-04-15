#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#ifdef LOCAL
#define err cerr
#else
#define err if (0) cerr
#endif

void solve() {
	int p, a, b;
	cin >> p >> a >> b;
	vector<string> grid(5, string(2*(a+b)+1, '.'));
	grid[0][0] = 'v';
	grid[1][0] = 'v';
	grid[2][0] = '>';
	for (int i = 0; i < a+b; i++) {
		grid[2][2*i+1] = 'S';
		grid[2][2*i+2] = '>';
	}
	for (int i = a+b; i--;) {
		grid[0][2*i+1] = grid[4][2*i+1] = '>';
		grid[0][2*i+2] = grid[4][2*i+2] = '>';
		if (i < a) {
			if (p%2 == 0) grid[1][2*i+1] = 'X';
			else grid[1][2*i+1] = '^';
			p /= 2;
		} else {
			if (p%3 == 0) {
				grid[1][2*i+1] = 'X';
				grid[3][2*i+1] = 'X';
			} else if (p%3 == 1) {
				grid[1][2*i+1] = '^';
				grid[3][2*i+1] = 'X';
			} else {
				grid[1][2*i+1] = '^';
				grid[3][2*i+1] = 'v';
			}
			p /= 3;
		}
	}
	grid[0][2*(a+b)] = 'v';
	grid[1][2*(a+b)] = 'v';
	grid[3][2*(a+b)] = '^';
	grid[4][2*(a+b)] = '^';
	cout << "5 " << 2*(a+b)+1 << "\n";
	for (int i = 0; i < 5; i++) cout << grid[i] << "\n";
}

signed main (signed argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) solve();
}

/*
*
*  ┏┓   ┏┓+ +
* ┏┛┻━━━┛┻┓ + +
* ┃   ━   ┃ ++ + + +
* ████━████+
* ◥██◤ ◥██◤ +
* ┃   ┻   ┃ 
* ┗━┓   ┏━┛  + + 
*   ┃   ┃ + + + +Code is far away from  
*   ┃   ┃ + bug with the llama protecting
*   ┃    ┗━━━┓ 神兽保佑,代码无bug 
*   ┃        ┣┓
*   ┃        ┏┛
*   ┗┓┓┏━┳┓┏┛ + + + +
*    ┃┫┫ ┃┫┫
*    ┗┻┛ ┗┻┛+ + + +
*/

//thanks cindy

