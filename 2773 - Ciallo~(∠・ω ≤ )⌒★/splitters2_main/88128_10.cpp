#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#define int long long
#define x first
#define y second
using namespace std;
typedef pair<int, int> PII;
typedef __int128 ll;
const int N = 2e5 + 10;

int p, a, b;
char g[10][N];
void f(int x, int y, char c) {
    g[x][y] = c;
}
bool qmi(int a, int b) {
    // cout << "!" << a << ' ' << b << ' ' << p << '\n';
	ll res = 1;
	ll t = 2;
	while(a) {
	    if((__int128)res * t > p) return 0;
	    // cout << a << ' ' << (int)t << '\n';
		if(a & 1) res = res * t;
		a >>= 1, t = t * t;
	}
	t = 3;
	while(b) {
	    if((__int128)res * t > p) return 0;
		if(b & 1) res = res * t;
		b >>= 1, t = t * t;
	}
	// cout << (int)res << '\n';
	if((int)res < p) return p -= (int)res, 1;
	return 0;
}
void work() {
    cin >> p >> a >> b;
    cout << 5 << ' ' << (a + b) * 2 + 2 << '\n';
    for(int i = 1; i <= 5; i ++) {
        for(int j = 1; j <= (a + b) * 2 + 2; j ++) g[i][j] = '.';
    }
    g[1][1] = 'v', g[2][1] = 'v', g[3][1] = '>';
    for(int i = 2; i <= (a + b) * 2 + 2; i ++) g[1][i] = '>', g[5][i] = '>';
    int num = 2;
    int ta = 0, tb = 0;
    while(ta < a) {
        ta ++;
        f(3, num, 'S');
        if(qmi(a - ta, b - tb)) g[2][num] = '^';
        else g[2][num] = 'X';
        num ++;
        g[3][num] = '>';
        num ++;
        if(!p) break;
    }
    while(tb < b) {
        tb ++;
        f(3, num, 'S');
        if(qmi(a - ta, b - tb)) g[2][num] = '^';
        else g[2][num] = 'X';
        if(qmi(a - ta, b - tb)) g[4][num] = 'v';
        else g[4][num] = 'X';
        num ++;
        g[3][num] = '>';
        num ++;
        if(!p) break;
    }
    g[2][num] = 'v', g[4][num] = '^';
    g[3][num] = '>';
    for(int i = 1; i <= 5; i ++, cout << '\n') {
        for(int j = 1; j <= num; j ++) {
            cout << g[i][j];
        }
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1; 
    cin >> T;
    while (T--) work();

    return 0;
}
