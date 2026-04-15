#include <bits/stdc++.h>
#define int long long
#define vi vector<int>
#define vvi vector<vi>
using namespace std;

struct Point {
    int x, y;

    bool operator<(const Point& a) const {
        if (x != a.x) return x < a.x;
        return y < a.y;
    }
};

void solve() {
    int k, n, m, p, q;
    cin >> k >> n >> m >> p >> q;
    vector<Point> v(k); // astroids
    map<Point, int> mp; // astroid map

    for (int i=0; i<k; i++) {
        cin >> v[i].x >> v[i].y;
        if (mp.find(v[i]) == mp.end())
            mp[v[i]] = i;
    }

    int cx = v[0].x, cy = v[0].y;
    for (int i=0; i<n*m; i++) {
        cx = (cx+q) % n;
        cy = (cy+p) % m;
        Point cur = {cx, cy};
        if (mp.count (cur) >= 1) {
            cout << mp[cur] << endl;
            return;
        }
    }
}

int32_t main() {
	int t;
    cin >> t;
    while (t--) solve();
}
