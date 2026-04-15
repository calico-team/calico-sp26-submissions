#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> wl, vl;
int n, m, d;

pair<double, pair<vector<int>, long long int>> f(long long int a) {
    vector<pair<double, int>> ll;
    for (int i = 0; i < m; ++i) {
        ll.emplace_back(wl[i] * abs(a * a - vl[i]) / double(vl[i]), i);
    }
    sort(ll.begin(), ll.end());
    vector<int> dl;
    for (int i = 0; i < d; ++i) {
        int i2 = ll.back().second;
        ll.pop_back();
        dl.push_back(i2);
    }
    double tot = 0;
    for (int i = 0; i < m - d; ++i) {
        tot += ll[i].first;
    }

    return make_pair(tot, make_pair(dl, a));
}

signed main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m >> d;
    for (int i = 0; i < m; ++i) {
        int r, c, v, w;
        cin >> r >> c >> v >> w;
        wl.push_back(w);
        vl.push_back(v);
    }

    long long int lv = 1, rv = 1'000'000'000, t1, t2;
    for (int i = 0; i < 60; ++i) {
        t1 = (lv * 2 + rv) / 3;
        t2 = (lv + rv * 2) / 3;
        if (f(t1) > f(t2)) lv = t1;
        else rv = t2;
    }

    pair<double, pair<vector<int>, int>> fin = min({ f(lv), f(t1), f(t2), f(rv) });
    int a = fin.second.second;
    vector<int> v = fin.second.first;

    for (int i = 0; i < n; ++i) {
        cout << a << ' ';
    }
    cout << '\n';
    cout << d << ' ';
    for (auto i: v) {
        cout << i + 1 << ' ';
    }

    return 0;
}