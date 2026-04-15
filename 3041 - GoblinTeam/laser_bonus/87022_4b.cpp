#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll exgcd(ll a,ll b,ll&x,ll&y){
    if(!b){x=1;y=0;return a;}
    ll g=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return g;
}
ll modinv(ll a,ll m){
    ll x,y;exgcd(a,m,x,y);
    x=(x%m+m)%m;
    return x;
}
ll crt(ll a,ll m,ll b,ll n){
    ll g=__gcd(m,n);
    if((b-a)%g!=0)return -1;
    ll mg=m/g,ng=n/g;
    ll rhs=(b-a)/g;
    ll inv=modinv(mg%ng,ng);
    ll k1=(rhs*inv)%ng;
    if(k1<0)k1+=ng;
    ll l=mg*n;
    ll t=a+k1*m;
    t=(t%l+l)%l;
    return t;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        ll K,N,M,P,Q;cin>>K>>N>>M>>P>>Q;
        vector<pair<ll,ll>>a(K);
        unordered_map<ll,int>mp;
        for(ll i=0;i<K;i++){
            cin>>a[i].first>>a[i].second;
            mp[a[i].first*M+a[i].second]=i;
        }
        ll sx=a[0].first,sy=a[0].second;
        ll bt=LLONG_MAX;int bi=-1;
        for(int i=0;i<K;i++){
            ll dx=(a[i].first-sx)%N;if(dx<0)dx+=N;
            ll dy=(a[i].second-sy)%M;if(dy<0)dy+=M;
            ll g1=__gcd(Q,N);
            if(dx%g1!=0)continue;
            ll n1=N/g1,q1=Q/g1,dx1=dx/g1;
            ll inv1=modinv(q1,n1);
            ll t1=(dx1*inv1)%n1;
            ll g2=__gcd(P,M);
            if(dy%g2!=0)continue;
            ll m1=M/g2,p1=P/g2,dy1=dy/g2;
            ll inv2=modinv(p1,m1);
            ll t2=(dy1*inv2)%m1;
            ll t=crt(t1,n1,t2,m1);
            if(t==-1)continue;
            if(t==0){
                ll L=n1/__gcd(n1,m1)*m1;
                t=L;
            }
            if(t<bt||(t==bt&&i<bi)){
                bt=t;bi=i;
            }
        }
        cout<<bi<<endl;
    }
    return 0;
}