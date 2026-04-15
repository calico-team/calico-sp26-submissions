#include<bits/stdc++.h>
using namespace std;

#define int long long 

const int N=1e5+10;
const int mod=998244353;
const int P=1e9+7;



void solve(){
    int k,n,m,p,q;cin>>k>>n>>m>>p>>q;
    map<pair<int,int>,int> mp;
    int x,y;cin>>x>>y;
    mp[{x,y}]=1;
    for(int i=2;i<=k;i++){
        int x,y;cin>>x>>y;
        mp[{x,y}]=i;
    }
    while(1){
        x=(x+q)%n,
        y=(y+p)%m;
        if(mp[{x,y}]){
            cout<<mp[{x,y}]-1<<endl;return ;
        }
    }
}   

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int tc=1;
    cin>>tc;
    while(tc--) solve();
}