#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()

set<array<int, 3>> asteroids; // (x, y, indx)
int N, M, P, Q, ans = -1;

void dfs(int x, int y) {
    auto it = asteroids.lower_bound({x, y, 0});
    if ((*it)[0] == x && (*it)[1] == y) {
        ans = (*it)[2];
        return; 
    }

    x = (x + Q) % N; 
    y = (y + P) % M;
    dfs(x, y);
}

void solve() {
    int K;
    cin >> K >> N >> M >> P >> Q; 
    asteroids.clear(); 
    int x1, y1; 
    for (int i = 0; i < K; i++) {
        int X, Y; cin >> X >> Y; 
        if (i == 0) 
            x1 = X, y1 = Y; 
        asteroids.insert({X, Y, i});
    }

    dfs((x1 + Q) % N, (y1 + P) % M);

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t; 
    while(t--)
        solve();
}