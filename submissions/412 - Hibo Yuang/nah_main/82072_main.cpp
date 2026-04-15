#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast, unroll-loops, inline")
typedef long long ll;
const ll MAX = 1e18;
const ll MOD = 1e9 + 7;
bool testcases = true;

void solve() {
    ll n, p, r, k;
    cin >> n >> p >> r >> k;
    vector<int> uwu(n+1);
    for (int i = 1; i <= n; i++) cin >> uwu[i];
    for (int i = 1; i <= n; i++) {
        p -= uwu[i];
        if (p < 0) {
            cout << "nah i’d lose" << endl;
            return;
        }
        if (i % k == 0) p += r;
    }
    cout << "nah i’d win" << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    if (testcases) cin >> t;
    for (int i = 1; i <= t; i++) solve();
    return 0;
}