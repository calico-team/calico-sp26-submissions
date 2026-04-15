#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    string a,b; cin >> a >> b;
    string ans = "";
    int r = 0;
    for(int i = 0; i < b.size(); i++) {
        while(a[r] != b[i]) {
            ans.push_back('#');
            r++;
        }
        ans.push_back(b[i]);
        r++;
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        solve();
    }
} 
