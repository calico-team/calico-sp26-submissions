#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vii = vector<pii>;
using vll = vector<pll>;
using vvii = vector<vii>;

#define rep(i, a, b)  for (int i = int(a); i < int(b); i++)
#define repr(i, a, b) for (int i = int(a); i > int(b); i--)
#define cinn(a, n)    rep(_, 0, n) cin >> a[_];
#define all(x)        begin(x), end(x)
#define each(x, l)    for (auto x : l)

const int MOD = 1e9 + 7;

void solve() {
    int num_aster, max_x, max_y, dx, dy;
    cin >> num_aster >> max_x >> max_y >> dy >> dx;

    vii points(num_aster);

    rep(i, 0, num_aster) {
        cin >> points[i].first >> points[i].second;
    }

    pii laser_point = points[0];

    while (true) {
        laser_point.first += dx;
        laser_point.second += dy;

        laser_point.first %= max_x;
        laser_point.second %= max_y;

        // cout << "travel: " << laser_point.first << " " << laser_point.second
        //      << endl;

        if (auto it = find(all(points), laser_point); it != points.end()) {
            cout << distance(points.begin(), it) << endl;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) solve();
}
