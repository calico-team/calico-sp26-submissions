#include<bits/stdc++.h>
using namespace std;

#define int long long 

const int N=1e5+10;
const int mod=998244353;
const int P=1e9+7;

int a[100005];

void solve(){
    int n;cin>>n;   
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cout<<a[1]<<' ';
    cout<<endl;
}   

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int tc=1;
    cin>>tc;
    while(tc--) solve();
}