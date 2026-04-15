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
    int n;
    cin >> n;
    vl e(n);
    cinn(e, n);

    // ll top_cost = abs(e[0] - e[1]) + abs(e[1] - e[2]);

    ll min_cost = 1e18;
    vl sol(3);

    for (ll a = max(0ll, e[0] - ll(1e2)); a < e[0] + ll(1e2); a++) {
        for (ll b = max(0ll, e[1] - ll(1e2)); b < e[1] + ll(1e2); b++) {
            for (ll c = max(0ll, e[2] - ll(1e2)); c < e[2] + ll(1e2); c++) {
                ll curr_cost = abs(a - b) + abs(b - c) + abs(e[0] - a) +
                               abs(e[1] - b) + abs(e[2] - c);
                if (curr_cost < min_cost) {
                    min_cost = curr_cost;
                    sol = { a, b, c };
                }
            }
        }
    }

    cout << sol[0] << " " << sol[1] << " " << sol[2] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) solve();
}
