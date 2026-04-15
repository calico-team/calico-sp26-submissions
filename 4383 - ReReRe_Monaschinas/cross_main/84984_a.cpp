// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>

using namespace std;
#define int long long
#define endl '\n'

void solve(){
    int n, m; cin>>n>>m;
    int arr[5] = {2, 0 , 3, 1, 4};
    for(int i=0; i<n; i++){
        int cur = arr[i];
        for(int j=0 ;j<m; j++){
            cout << cur << " ";
            cur  = (cur + 1) % 5;
        }
        cout << endl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1; cin>>t;
    while(t--)
        solve();
}
