#include <bits/stdc++.h>
using namespace std;
#define int long long
#define v vector
#define int long long

struct pos {
	int t, m1, m2, m3, b;
};

void solve() {
	int N, M; cin >> N >> M;
	v<v<int>> a(N, v<int>(M, 0));
	v<v<pos>> b(N, v<pos>(M));
	b[0][0] = {0, 1, 2, 3, 4};
	for (int y = 1; y < M; y++) {
		b[0][y].m1 = b[0][y - 1].m2;
		b[0][y].m2 = b[0][y - 1].m3;
		b[0][y].t  = b[0][y - 1].b;
		b[0][y].m3 = b[0][y - 1].t;
		b[0][y].b  = b[0][y - 1].m1;
	}
	for (int x = 1; x < N; x++) {
		b[x][0].t  = b[x - 1][0].m2;
		b[x][0].m2 = b[x - 1][0].b;
		b[x][0].b  = b[x - 1][0].m3;
		b[x][0].m1 = b[x - 1][0].t;
		b[x][0].m3 = b[x - 1][0].m1;
		for (int y = 1; y < M; y++) {
			b[x][y].m1 = b[x][y - 1].m2;
			b[x][y].m2 = b[x][y - 1].m3;
			b[x][y].t  = b[x][y - 1].b;
			b[x][y].m3 = b[x][y - 1].t;
			b[x][y].b  = b[x][y - 1].m1;
		}
	}
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			a[x][y] = b[x][y].m2;
			cout << a[x][y] << (y == M - 1 ? "" : " ");
		}
		cout << "\n";
	}
}

int32_t main() {
	int T; cin >> T; 
	while (T--) solve();
}