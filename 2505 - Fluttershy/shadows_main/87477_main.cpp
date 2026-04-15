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
    vector<string> s1(n);
    vector<string> s2(n);
    FOR(i, 0, n, 1) {
        cin >> s1[i];
    }
    FOR(i, 0, n, 1) {
        cin >> s2[i];
    }
    //Observations
    //For min, we take advantage of z axis.
    //We can always place the needed amount using max cnt of # out of each row of the two strings
    //For max, we fill everything necessary to make the shadow
    ll outMin = 0;
    ll outMax = 0;
    for (ll r = 0; r < n; r++) {
        outMax += count(s1[r].begin(), s1[r].end(), '#') * count(s2[r].begin(), s2[r].end(), '#');
        outMin += max(count(s1[r].begin(), s1[r].end(), '#'), count(s2[r].begin(), s2[r].end(), '#'));
    }
    cout << outMax << " " << outMin << "\n";
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
