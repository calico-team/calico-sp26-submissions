#include<bits/stdc++.h>
using namespace std;

#define int long long 

const int N=1e5+10;
const int mod=998244353;
const int P=1e9+7;

void solve(){
    int n;cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    for(int i=1;i<=n;i++) cout<<a[n/2+1]<<' ';
    cout<<endl;
}   

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int tc=1;
    cin>>tc;
    while(tc--) solve();
}