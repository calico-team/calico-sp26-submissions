#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct pt{ll x,y;}a[100010];

ll gcd(ll a,ll b,ll&x,ll&y){
    if(!b){x=1;y=0;return a;}
    ll nx,ny,d=gcd(b,a%b,nx,ny);
    x=ny;y=nx-ny*(a/b);
    return d;
}
ll inv(ll a,ll m){
    ll x,y;gcd(a,m,x,y);
    return(x%m+m)%m;
}
ll crt(ll a,ll m,ll b,ll n){
    ll x,y,g=gcd(m,n,x,y);
    if((a-b)%g)return-1;
    ll L=m/g*n,r=(a+(b-a)/g*x%(n/g)*m)%L;
    return r<0?r+L:r;
}

int main(){
    int T;cin>>T;
    while(T--){
        ll k,n,m,p,q;cin>>k>>n>>m>>p>>q;
        for(int i=0;i<k;i++)cin>>a[i].x>>a[i].y;
        ll sx=a[0].x,sy=a[0].y,ans=LLONG_MAX,idx=0;
        for(int i=0;i<k;i++){
            ll dx=(a[i].x-sx)%n;if(dx<0)dx+=n;
            ll dy=(a[i].y-sy)%m;if(dy<0)dy+=m;
            ll x,y,g1=gcd(q,n,x,y);if(dx%g1)continue;
            ll n1=n/g1,t1=dx/g1*inv(q/g1%n1,n1)%n1;
            ll g2=gcd(p,m,x,y);if(dy%g2)continue;
            ll m1=m/g2,t2=dy/g2*inv(p/g2%m1,m1)%m1;
            ll s=crt(t1,n1,t2,m1);if(s==-1)continue;
            ll g3=gcd(n1,m1,x,y),per=n1/g3*m1;
            if(!s)s=per;
            if(s<ans){ans=s;idx=i;}
        }
        cout<<idx<<"\n";
    }
}
