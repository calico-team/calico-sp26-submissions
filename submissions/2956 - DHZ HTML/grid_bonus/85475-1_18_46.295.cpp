#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using ll = long long;

void solve() {
    ll n;
    cin >> n;
    
    ll a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll l[n], r[n];
    l[0] = a[0]; r[0] = a[0];
    for (int i = 1; i < n; i++) {
        ll u = l[i - 1], v = r[i - 1];

        if (u <= a[i] && a[i] <= v) {
            l[i] = a[i];
            r[i] = a[i];
        } else if (a[i] < u) {
            l[i] = a[i];
            r[i] = u;
        } else {
            l[i] = v;
            r[i] = a[i];
        }
    }

    ll b[n];
    b[n - 1] = l[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (l[i] <= b[i + 1] && b[i + 1] <= r[i]) {
            b[i] = b[i + 1];
        } else if (b[i + 1] < l[i]) {
            b[i] = l[i];
        } else {
            b[i] = r[i];
        }
    }

    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }

    cout << "\n";
}

int main() {
    fastio;

    ll tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
}