#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll exgcd(ll a,ll b,ll &x,ll &y){
    if(!a){x=0;y=1;return b;}
    ll x1,y1,g=exgcd(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
    return g;
}

bool solve(ll a,ll b,ll m,ll &r,ll &mod){
    ll x,y,g=exgcd(a,m,x,y);
    if(b%g) return false;
    mod=m/g;
    x=(x%mod+mod)%mod;
    r=(x*(b/g))%mod;
    return true;
}

bool crt(ll r1,ll m1,ll r2,ll m2,ll &r,ll &m){
    ll x,y,g=exgcd(m1,m2,x,y);
    if((r2-r1)%g) return false;

    ll lcm=(m1/g)*m2;
    ll k,km;

    solve(m1,(r2-r1),m2,k,km);

    r=(r1+k*m1)%lcm;
    if(r<0) r+=lcm;
    m=lcm;
    return true;
}

void solve_case(){
    ll K,N,M,P,Q;
    cin>>K>>N>>M>>P>>Q;

    vector<pair<ll,ll>> a(K);
    for(auto &p:a) cin>>p.first>>p.second;

    ll x0=a[0].first, y0=a[0].second;

    ll best=1e18, idx=-1;

    for(int i=0;i<K;i++){
        ll dx=(a[i].first-x0%N+N)%N;
        ll dy=(a[i].second-y0%M+M)%M;

        ll r1,m1,r2,m2;

        if(!solve(Q,dx,N,r1,m1)) continue;
        if(!solve(P,dy,M,r2,m2)) continue;

        ll t,mod;
        if(crt(r1,m1,r2,m2,t,mod)){
            if(t==0) t=mod;
            if(t<best){
                best=t;
                idx=i;
            }
        }
    }

    cout<<idx<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T;
    while(T--) solve_case();
}