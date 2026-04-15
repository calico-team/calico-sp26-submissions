#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll egcd(ll a, ll b, ll &x, ll&y){
    if(!a){
        x=0;
        y=1;
        return b;
    }
    ll x1,y1,d=egcd(b%a,a,x1,y1);
    x=y1-(b/a)*x1;y=x1;
    return d;
}

ll inv(ll a,ll b){
    ll x,y; egcd(a,b,x,y);
    return(x%b+b)%b;
}

void solve(){
    ll k,m,n,p,q;cin>>k>>m>>n>>p>>q;

    vector<pair<ll,ll>> a;
    for(ll i=0;i<k;i++){
        ll x,y;cin>>x>>y;
        a.push_back({x,y});
    }
    ll sx=a[0].first,sy=a[0].second;
    ll gx=gcd(q,m),gy=gcd(p,n);
    ll ip=inv((q/gx)%(m/gx),m/gx),iq=inv((p/gy)%(n/gy),n/gy);
    ll g=gcd(m/gx,n/gy),my=n/gy/g,imx=inv((m/gx/g)%my,my);
    ll lcm=m*n/gx/gy/g;
    ll ans=lcm;
    vector<ll> t(k,-1);
    for(ll i=0;i<k;i++){
        ll x=a[i].first,y=a[i].second;
        ll dx=(x-sx+m)%m,dy=(y-sy+n)%n;
        if(dx%gx!=0 || dy%gy!=0){
            continue;
        }
        ll kx=(dx/gx*ip)%(m/gx),ky=(dy/gy*iq)%(n/gy);
        ll d=((ky-kx)%(n/gy)+(n/gy))%(n/gy);
        if(d%g==0){
            ll time=kx+((d/g*imx)%my)*m/gx;
            if(time==0) time=lcm;
            t[i]=time;
            ans=min(ans,time);
        } 
    }
    for(ll i=0;i<k;i++){
        if(t[i]==ans){
            cout<<i<<'\n';
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while (t--) solve();
}
