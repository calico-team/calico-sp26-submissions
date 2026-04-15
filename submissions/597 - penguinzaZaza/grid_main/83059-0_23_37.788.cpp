#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int t, n;

void solve() {
    cin >> n;
    vector<int> a(n);
    for (auto &e: a) cin >> e;
    vector<int> aa = a;
    sort(aa.begin(), aa.end());
    vector<int> b1 = a;
    vector<int> b2(n, aa[1]);
    ll s1 = abs(b1[0] - b1[1]) + abs(b1[1] - b1[2]) + abs(a[0] - b1[0]) + abs(a[1] - b1[1]) + abs(a[2] - b1[2]);
    ll s2 = abs(b2[0] - b2[1]) + abs(b2[1] - b2[2]) + abs(a[0] - b2[0]) + abs(a[1] - b2[1]) + abs(a[2] - b2[2]);
    vector<int> b;
    if (s1 < s2) b = b1;
    else b = b2;
    for (auto &e: b) cout << e << ' '; cout << '\n';
}

int main() {
    cin >> t;
    while (t--) solve();
}