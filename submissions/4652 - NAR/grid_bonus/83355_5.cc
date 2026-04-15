#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<ll> a(n + 1), l(n + 1), r(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    l[1] = r[1] = a[1];
    for(int i = 2; i <= n; i++) {
        if(a[i] < l[i - 1]) {
            l[i] = a[i];
            r[i] = l[i - 1];
        } else if(a[i] > r[i - 1]) {
            l[i] = r[i - 1];
            r[i] = a[i];
        } else {
            l[i] = r[i] = a[i];
        }
    }

    b[n] = l[n];
    for(int i = n - 1; i >= 1; i--) {
        b[i] = min(max(b[i + 1], l[i]), r[i]);
    }

    for(int i = 1; i <= n; i++) {
        cout << b[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}