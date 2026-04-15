#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
const ll MOD = 1e9+7;
const ll MAXX = 1e16;
const int INF = 1e9 + 7;

int inv(int a,int b){
    if(a<=1) return a;
    else return b-(b/a)*inv(b%a,b)%b;
}

void solve(){
    int k,m,n,p,q;cin>>k>>m>>n>>p>>q;

    vector<pair<int,int>> a;
    for(int i=0;i<k;i++){
        int x,y;cin>>x>>y;
        a.push_back({x,y});
    }
    int sx=a[0].first,sy=a[0].second;
    int gx=gcd(q,m),gy=gcd(p,n);
    int ip=inv((q/gx)%(m/gx),m/gx),iq=inv((p/gy)%(n/gy),n/gy);
    int g=gcd(m/gx,n/gy),my=n/gy/g,imx=inv((m/gx/g)%my,my);
    int lcm=m*n/gx/gy/g;
    int ans=lcm;
    vector<int> t(k,-1);
    for(int i=0;i<k;i++){
        int x=a[i].first,y=a[i].second;
        int dx=(x-sx+m)%m,dy=(y-sy+n)%n;
        if(dx%gx!=0 || dy%gy!=0){
            continue;
        }
        int kx=(dx/gx*ip)%(m/gx),ky=(dy/gy*iq)%(n/gy);
        int d=((ky-kx)%(n/gy)+(n/gy))%(n/gy);
        if(d%g==0){
            int time=kx+((d/g*imx)%my)*m/gx;
            if(time==0) time=lcm;
            t[i]=time;
            ans=min(ans,time);
        } 
    }
    for(int i=0;i<k;i++){
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
