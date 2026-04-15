#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
int MV = 1e18;

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << (i+2*j) % 5 << " ";
        }
        cout << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}