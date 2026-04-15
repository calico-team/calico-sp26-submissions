#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int k, n, m, p, q;
        cin >> k >> n >> m >> p >> q;
        int x, y;
        set<pair<int, int>> s;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;
            if (i == 0) {
                x = a;
                y = b;
            }
            s.insert({a, b});
            mp[{a, b}] = i;
        }
        while (true) {
            x = (x + q) % n;
            y = (y + p) % m;
            if (s.count({x, y})) {
                cout << mp[{x, y}] << "\n";
                break;
            }
        }
    }
}