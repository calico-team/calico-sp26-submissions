#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int l, w, e, r;
        cin >> l >> w >> e >> r;
        cout << e / (2 * r * (l + w)) << "\n";
    }
}