#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O1")
#define ll long long
#define pii pair<ll,ll>
#define pi pair<ll,pii>
#define fi first
#define se second

const ll N=1e5+1005,MOD=1e9+7,INF=1e18;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);


    int t=1;cin>>t;
    while(t--){
        ll n,m;cin>>n>>m;
        vector<ll> v={3,0,4,1,2};
        for(int i=1; i<=n; i++){
            int id;
            if(i%5==1)id=0;
            else if(i%5==2)id=3;
            else if(i%5==3)id=1;
            else if(i%5==4)id=4;
            else id=2;
            for(int j=1; j<=m; j++){
                cout<<v[id]<<" ";
                id=(id+1)%5;
            }
            cout<<"\n";
        }
    }
}
