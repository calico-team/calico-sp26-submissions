// soab

#include <bits/stdc++.h>

using namespace std;

#define int long long 
#define nl '\n'

void io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}   

signed main() {
    io();

    int t; cin >> t;
    while(t--) {
        int l, w, e, r; cin >> l >> w >> e >> r;
        cout << e / ((w + l) * 2 * r) << nl;
    }

    return 0;
}   