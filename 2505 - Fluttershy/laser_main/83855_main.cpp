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
    ll k, n, m, delY, delX;
    cin >> k >> n >> m >> delY >> delX;
    ll x, y;
    cin >> x >> y;
    pll laserStart = {x, y};
    map<pll, ll> idx;
    idx[laserStart] = 0;
    FOR(i, 1, k, 1) {
        ll x, y;
        cin >> x >> y;
        idx[{x, y}] = i;
    }
    for (ll i = 0; i < 1e6; i++) {
        laserStart.first += delX;
        laserStart.second += delY;
        laserStart.first %= n;
        laserStart.second %= m;
        if (idx.find(laserStart) != idx.end()) {
            cout << idx[laserStart] << "\n";
            return;
        }
    }
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
