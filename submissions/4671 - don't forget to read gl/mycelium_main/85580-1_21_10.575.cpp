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


    int tt=1;cin>>tt;
    map<pii,ll> t;
    while(tt--){
        t.clear();
        ll a,b,x,y;
        cin>>a>>b>>x>>y;
        x-=a;y-=b;
        a=b=0;
        queue<pii> v,p;
        v.push({0,0});
        p.push({x,y});
        ll dx[]={0,0,-1,1};
        ll dy[]={1,-1,0,0};
        t[{0,0}]=1;
        t[{x,y}]=2;
        ll ans=1;
        for(int i=1; i<=150; i++){
            if(i%2==0){
                vector<pii> k;
                while(!v.empty()){
                    pii j=v.front();
                    v.pop();
                    for(int ii=0; ii<4; ii++){
                        ll nx=j.fi+dx[ii];
                        ll ny=j.se+dy[ii];
                        if(t[{nx,ny}])continue;
                        k.push_back({nx,ny});
                        t[{nx,ny}]=1;
                    }
                }
                for(pii j : k)v.push(j);
            }
            if(i%7==0){
                vector<pii> k;
                while(!p.empty()){
                    pii j=p.front();
                    p.pop();
                    for(int ii=0; ii<4; ii++){
                        ll nx=j.fi+dx[ii];
                        ll ny=j.se+dy[ii];
                        if(t[{nx,ny}]==1 || t[{nx,ny}]==2)continue;
                        k.push_back({nx,ny});
                        t[{nx,ny}]=2;
                        ans++;
                    }
                }
                for(pii j : k)p.push(j);
            }
        }
        cout<<ans<<"\n";
    }
}
