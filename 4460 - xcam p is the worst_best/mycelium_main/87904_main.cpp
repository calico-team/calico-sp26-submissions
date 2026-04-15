#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

bool visited[2000][2000];

void clear() {
	for (int i=0; i<2000; i++){
		for (int j=0; j<2000; j++) {
			visited[i][j] = 0;
		}
	}
}


ll dx[] = {1, -1, 0, 0};
ll dy[] = {0, 0, 1, -1};

bool invalid(ll x, ll y) {
	return (x >= 1000 || y >= 1000 || x < -1000 || y < -1000);
}
void update(ll x, ll y) {
	if (invalid(x, y)) return;
	visited[x + 1000][y + 1000] = 1;
}

bool vis(ll x, ll y) {
	if (invalid(x, y)) return 1;
	return visited[x + 1000][y + 1000];
}

int solve() {
	clear();
	ll A, B, C, D; cin >> A >> B >> C >> D;
	
	queue<array<ll, 3>> M, G; M.push({C, D, 0}), G.push({A, B, 0}); update(C, D); update(A, B);
	
	ll Mycelium = 0;
	
	for (int i=1; i<1000; i++) {
		if (i % 2 == 0) {
			// grass
			while (!G.empty()) {
				if (G.front()[2] == i) break;
				auto [X, Y, asdf] = G.front(); G.pop();
				for (int j=0; j<4; j++) {
					ll nx = X + dx[j], ny = Y + dy[j];
					if (invalid(nx, ny)) continue;
					if (vis(nx, ny)) continue;
					update(nx, ny);
					G.push({nx, ny, i});
					
				}
			}
		}
		
		if (i % 7 == 0) {
			ll old_mycelium = Mycelium;
			// mycelium
			while (!M.empty()) {
				if (M.front()[2] == i) break;
				auto [X, Y, asdf] = M.front(); M.pop();
				// cout << X << ' ' << Y << '\n';
				Mycelium++;
				for (int j=0; j<4; j++) {
					ll nx = X + dx[j], ny = Y + dy[j];
					// cout << "||" << nx << ' ' << ny << " ";
					if (invalid(nx, ny)) continue;
					if (vis(nx, ny)) continue;
					// cout << "!";
					update(nx, ny);
					M.push({nx, ny, i});
					
				}
			}
			if (old_mycelium == Mycelium) break;
		}
	}
	
	cout << Mycelium << '\n';
	return 0;
}
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	ll Q;
	cin >> Q;
	while (Q--) {
		solve();
	}
	
	return 0;
}