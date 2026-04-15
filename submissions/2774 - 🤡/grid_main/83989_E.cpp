#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    int a[n]; for (auto &e : a) cin >> e;
    int d = 0;
    for (int i = 0; i < n-1; i++) d += abs(a[i] - a[i+1]);
    int b[n]; for (int i = 0; i < n; i++) b[i] = a[i];
    sort(b, b+n);
    int d2 = d + b[1] - b[0] + b[2] - b[1];
    d *= 2;
    if (d < d2) for (int i = 0; i < n; i++) cout << a[i] << ' ';
    else for (int i = 0; i < n; i++) cout << b[1] << ' '; cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T; cin >> T;
    while (T--) solve();
}

