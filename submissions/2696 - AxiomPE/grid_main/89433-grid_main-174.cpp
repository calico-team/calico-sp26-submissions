#include <bits/stdc++.h>
using namespace std;

void slv() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
        cout << a[i] << (i + 1 < n ? ' ' : '\n');
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    if (cin >> t) while (t--) slv();
    return 0;
}