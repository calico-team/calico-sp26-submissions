// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>

using namespace std;
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;
   char a[n][n] , b[n][n];
   int count[n] = {0};
   for(int i=0;i<n; i++){
    for(int j=0; j<n; j++) cin >> a[i][j], count[i] += a[i][j] == '#';
   }
   int mx = 0;
   int mn = 0;
   for(int i=0;i<n; i++){

    int cur = 0;
    for(int j=0; j<n; j++){
        cin >> b[i][j];
        if(b[i][j] == '#'){
            mx += count[i];
            cur++;
        }
    }
    mn += max(count[i], cur);
   }
   cout << mx << " " << mn << endl;


}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1; cin>>t;
    while(t--)
        solve();
}
