#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
const ll INF = numeric_limits<ll>::max();
const ll MOD = 1000000007;
const ll N = 200005;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using ordered_set = tree<
    pair<ll, int>,
    null_type,
    less<pair<ll, int> >,
    rb_tree_tag,
    tree_order_statistics_node_update
>;
#define FOR(i, l, r, inc) for (ll i = l; i < r; i += inc)

vector<ll> dx = {1, 0, -1, 0};
vector<ll> dy = {0, 1, 0, -1};

void solve() {
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1 += 50, y1 += 50, x2 += 50, y2 += 50;
    set<pll> grass;
    grass.insert({x1, y1});
    set<pll> my;
    my.insert({x2, y2});
    //100*100 grid, +50 offset for coordinates
    for (int time = 1; time <= 150; time++) {
        set<pll> NEWg, NEWm;
        if (time % 2 == 0) {
            for (auto [x, y]: grass) {
                for (ll i = 0; i < 4; i++) {
                    ll nx = x + dx[i], ny = y + dy[i];
                    if (nx >= 0 && nx < 100 && ny >= 0 && ny < 100) {
                        if (grass.find({nx, ny}) == grass.end() && my.find({nx, ny}) == my.end()) {
                            NEWg.insert({nx, ny});
                        }
                    }
                }
            }
        }
        if (time % 7 == 0) {
            for (auto [x, y]: my) {
                for (ll i = 0; i < 4; i++) {
                    ll nx = x + dx[i], ny = y + dy[i];
                    if (nx >= 0 && nx < 100 && ny >= 0 && ny < 100) {
                        if (my.find({nx, ny}) == my.end() && grass.find({nx, ny}) == grass.end()) {
                            NEWm.insert({nx, ny});
                        }
                    }
                }
            }
        }
        if (time % 2 == 0 && time % 7 == 0) {
            for (auto [x, y]: NEWg) {
                if (NEWm.find({x, y}) != NEWm.end()) NEWm.erase({x, y});
            }
        }
        for (auto x: NEWg) grass.insert(x);
        for (auto x: NEWm) my.insert(x);
    }
    cout << my.size() << "\n";
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t;
    cin >> t;
    //t = 1;
    FOR(test, 1, t + 1, 1) {
        //cout << "TEST" << test << "\n";
        solve();
    }
    return 0;
}
