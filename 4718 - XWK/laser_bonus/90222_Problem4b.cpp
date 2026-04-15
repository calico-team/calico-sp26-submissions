#include <bits/stdc++.h>
#define int long long
using namespace std;
int phi[1000001];
int gcd(int a,int b) {
    return (b==0?a:gcd(b,a%b));
}
int lcm(int a,int b) {
    return (a/gcd(a,b))*b;
}
int bexp(int a,int b,int MOD) {
    int res=a,rem=1,e=b;
    while (e>1) {
        if (e&1) rem = rem*res%MOD;
        e>>=1;
        res = res*res%MOD;
    }
    return res*rem%MOD;
}
int inv(int x,int MOD) {
    return bexp(x,phi[MOD]-1,MOD);
}
int h(int c,int r,int d) {
    if (r<=0) return 0;
    int g=gcd(c,r);
    c/=g; r/=g;
    if (gcd(c,d)!=1) return -1;
    return (r*inv(c,d))%d;
}
int crt(int r1,int d1,int r2,int d2) {
    if (d1==d2) {
        if (r1==r2) return r1;
        return -1;
    }
    if (r1==r2) return r1;
    int s=((r2-(r1%d2))+d2)%d2;
    //cout<<"wmk"<<d1%d2<<" "<<s<<" "<<d2<<endl;
    int tem=h(d1%d2,s,d2);
    if (tem<0) return -1;
    return (r1+tem*d1);
}
void solve() {
    int k,n,m,p,q; cin>>k>>n>>m>>p>>q;
    vector<pair<int,int>> a(k);
    vector<pair<int,int>> ans;
    for (auto &i:a) cin>>i.first>>i.second;
    for (int i=1;i<k;i++) {
        a[i].first = (a[i].first-a[0].first+n)%n;
        a[i].second = (a[i].second-a[0].second+m)%m;
    }
    a[0] = {0,0};
    ans.push_back({lcm(n,m),0});
    for (int i=1;i<k;i++) {
        int g1=gcd(gcd(q,a[i].first),n),g2=gcd(gcd(p,a[i].second),m);
        int tn=n/g1,tm=m/g2;
        int m1=h(q/g1,a[i].first/g1,tn),m2=h(p/g2,a[i].second/g2,tm);
        //cout<<m1<<" "<<tn<<" "<<m2<<" "<<tm<<endl;
        if (m1<0 || m2<0) continue;
        int pb=(crt(m1,tn,m2,tm));
        if (pb==0) pb+=lcm(tn,tm);
        if (pb>=0) ans.push_back({pb,i});
    }
    sort(begin(ans),end(ans));
    //for (auto i:ans) cout<<i.first<<" "<<i.second<<endl;
    cout<<ans[0].second<<"\n";
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.in","r",stdin);
    for (int i=1;i<=1000000;i++) phi[i] = i;
    for (int i=2;i<=1000000;i++) {
        if (phi[i]==i) {
            for (int j=i;j<=1000000;j+=i) phi[j]-=(phi[j]/i);
        }
    }
    int t; cin>>t;
    while (t--) solve();
    return 0;
}