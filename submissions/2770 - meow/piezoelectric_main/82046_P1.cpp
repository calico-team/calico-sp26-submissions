#include <bits/stdc++.h>

using namespace std;

void solve(){
    int l, w, e, r; cin >> l >> w >> e >> r;
    int p = (l+2)*2*r;
    cout << e/p << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--){
        solve();
    }
    return 0;
}