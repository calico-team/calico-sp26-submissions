#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define ll long long



void solve() {
    int k, n, m, p, q; cin >> k >> n >> m >> p >> q;
    vector<pair<int, int>> a(k);
    set<vector<int>> s; 
    for (int i = 0; i < k; i++) {
        cin >> a[i].first >> a[i].second;
        s.insert({a[i].first, a[i].second, i});
    }
    int x = a[0].first;
    int y = a[0].second;
    while (1) {
        x = (x + q) % n;
        y = (y + p) % m;
        auto it = s.lower_bound({x, y, 0});
        if (it != s.end() && (*it)[0] == x && (*it)[1] == y) {
            cout << (*it)[2] << endl; 
            return;
        }
    }
}




int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while (tt--) solve();
    return 0;
}
