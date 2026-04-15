#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()

void solve() {
    int l, w, e, r; 
    cin >> l >> w >> e >> r; 

    cout << e / (2 * (l + w) * r) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t; 
    while(t--)
        solve();
}