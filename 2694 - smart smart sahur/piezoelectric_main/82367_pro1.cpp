#include <bits/stdc++.h>
#define DEBUG false
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define endl '\n'
using namespace std;
void solve(){
    int l, w, e, r;
    cin>>l>>w>>e>>r;
    int perimeter = (2*l+2*w);
    int totalE = perimeter*r;
    cout<<e/totalE<<endl;
}
signed main() {
    if(!DEBUG){
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    }
    else{
        (void)freopen("test.in", "r", stdin);
        (void)freopen("test.out", "w", stdout); 
    }
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}