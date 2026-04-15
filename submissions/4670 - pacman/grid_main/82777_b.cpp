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
    int a = 0, b=0;
    for (int i = 1; i < n; i++) {
        a += abs(v[i] - v[i-1]);
    }
    sort(all(v));
    int sum = 0, ans;
    for (int i = 0; i < n; i++) {
        sum += v[i] - v[0];
    }
    b = sum, ans = 0;
    for (int i = 1; i < n; i++) {
        sum -= (n - i) * (v[i] - v[i-1]);
        sum += (i + 1) * (v[i] - v[i-1]);
        if (sum < b) {
            b = sum;
            ans = i;
        }
    }
    if (a < b) {
        for (int &i : v) cout << i << ' ';
    }
    else {
        for (int &i : v) cout << v[ans] << ' ';
    }
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
