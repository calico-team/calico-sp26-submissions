#include<bits/stdc++.h>
using namespace std;

#define int long long 

const int N=1e5+10;
const int mod=998244353;
const int P=1e9+7;

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){cout<<(i+2*j)%5<<' ';}
        cout<<endl;
    }

}   

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int tc=1;
    cin>>tc;
    while(tc--) solve();
}