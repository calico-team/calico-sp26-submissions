#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 2e18;

ll ccr(vector<ll> &a, vector<ll> &b) {
    ll ans = 0;
    int n = a.size();
    for (int i = 1; i < n; ++i) {
        ans += abs(a[i] - a[i - 1]);
        ans += abs(b[i] - b[i - 1]);
    }
    for (int i = 0; i < n; ++i) {
        ans += abs(a[i] - b[i]);
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0;i < n;i ++) {
        cin >> a[i];
    }
    
    ll c1 = ccr(a, a);
    sort(a.begin(), a.end());
    
    ll med = a[n / 2];
    
    vector<ll> b(n, med);
    
    ll c2 = ccr(a, b);
    
    if (c1 <= c2) {
        for (int i: a) {
            cout << i << ' ';
        }
        cout << '\n';
    }
    
    else {
        for (int i: b) {
            cout << i << ' ';
        }
        
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t --)
        solve();
    return 0;
}