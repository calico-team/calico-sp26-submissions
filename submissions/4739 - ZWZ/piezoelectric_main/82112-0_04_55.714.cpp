#include<bits/stdc++.h>
using namespace std;

#define int long long 

const int N=1e5+10;
const int mod=998244353;
const int P=1e9+7;

void solve(){
    int n,m,e,r;cin>>n>>m>>e>>r;
    int el=2*(n+m)*r;
    cout<<(e+el-1)/el<<endl;
}   

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int tc=1;
    cin>>tc;
    while(tc--) solve();
}