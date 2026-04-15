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
    ll n;
    cin >> n;
    vll a(n);
    for (auto &x: a) cin >> x;
    ll out = 0;
    FOR(i, 1, n, 1) out += abs(a[i] - a[i - 1]);
    out *= 2;
    //Upper bound : 2 * (adjacent in top row)
    //Observations:
    //At each i, we want to minimize distance between the two neighbors
    //Median minimizes distance?
    sort(a.begin(), a.end());
    ll median;
    if (n & 1) median = a[n / 2];
    else median = (a[n / 2] + a[n / 2 - 1]) / 2;
    ll cand = 0;
    FOR(i, 0, n, 1) {
        cand += abs(a[i] - median);
    }
    cand += out / 2;
    if (cand < out) {
        for (ll i = 0; i < n; i++) {
            cout << median << " ";
        }
        cout << "\n";
    } else {
        for (ll i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
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
