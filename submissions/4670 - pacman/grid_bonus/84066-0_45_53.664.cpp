#include <bits/stdc++.h>
#define GOOD_LUCK ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"
#define ff first
#define ss second
#define pb push_back
#define all(v) v.begin(), v.end()
using namespace std;

constexpr int MAX = 2e+5 + 1, INF = 2e+16, MOD = 1e+9 + 7, K = 31;

void _() {
    int n;
    cin >> n;
    vector <int> v(n);
    for (int &i : v) cin >> i;
    vector <int> l(n), r(n);
    l[0] = r[0] = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] < l[i-1]) {
            l[i] = v[i];
            r[i] = l[i-1];
        }
        else if (v[i] > r[i-1]) {
            l[i] = r[i-1];
            r[i] = v[i];
        }
        else l[i] = r[i] = v[i];
    }
    vector <int> res(n);
    res.back() = l.back();
    for (int i = n - 2; i >= 0; i--) {
        if (res[i+1] < l[i]) {
            res[i] = l[i];
        }
        else if (res[i+1] > r[i]) {
            res[i] = r[i];
        }
        else res[i] = res[i+1];
    }
    for (int &i : res) cout << i << ' ';
}

signed main() {

    GOOD_LUCK

    int tests=1;
    cin >> tests;
    for (int i=1; i <= tests; i++) {
        _();
        cout << endl;
    }

    return 0;
}
