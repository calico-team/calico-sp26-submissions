#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> L(n),R(n);
    L[0] = a[0];
    R[0] = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] < L[i - 1]) {
            L[i] = a[i];
            R[i] = L[i - 1];
        } else if (a[i] >R[i - 1]) {
            L[i] = R[i - 1];
            R[i] = a[i];
        } else {
            L[i] = a[i];
            R[i] = a[i];
        }
    }


    vector<ll> b(n);
    b[n - 1] = L[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        b[i] = max(L[i], min(R[i], b[i + 1]));
    }
    for (int i = 0; i < n; ++i) {
        cout << b[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}