#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int l,w,need,perStep;
    cin >> l >> w >> need >> perStep;

    int perPeri = (l+w)*2*perStep;
    cout << ceil((double)(need)/(double)(perPeri)) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        solve();
    }
} 
