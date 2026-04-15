#include<bits/stdc++.h>
using namespace std;

long long extgcd(long long a,long long b,long long &x,long long &y){
    if(!b){x=1;y=0;return a;}
    long long x1,y1,g=extgcd(b,a%b,x1,y1);
    x=y1;y=x1-(a/b)*y1;
    return g;
}

long long msolve(long long a,long long c,long long m){
    long long x,y,g=extgcd(a,m,x,y);
    if(c%g)return -1;
    long long t=(x*(c/g))%(m/g);
    return t<0?t+m/g:t;
}

int solve(int k,long long n,long long m,long long p,long long q,vector<pair<long long,long long>>&a){
    long long sx=a[0].first,sy=a[0].second,lazarbeam=LLONG_MAX;
    int ans=-1;
    for(int i=1;i<k;i++){
        long long dx=(a[i].first-sx+n)%n,dy=(a[i].second-sy+m)%m;
        long long t1=msolve(q,dx,n);
        if(t1<0)continue;
        long long m1=n/__gcd(q,n),t2=msolve(p,dy,m);
        if(t2<0)continue;
        long long m2=m/__gcd(p,m),df=((t2-t1)%m2+m2)%m2,g=__gcd(m1,m2);
        if(df%g)continue;
        long long s=msolve(m1/g,df/g,m2/g);
        if(s<0)continue;
        long long lc=m1/g*m2,t=((t1+m1*s)%lc+lc)%lc;
        if(!t)t=lc;
        if(t<lazarbeam){lazarbeam=t;ans=i;}
    }
    if(n/__gcd(n,m)*m<lazarbeam)ans=0;
    return ans;
}

void read_your_input(){
    int t;cin>>t;
    while(t--){
        int k;long long n,m,p,q;
        cin>>k>>n>>m>>p>>q;
        vector<pair<long long,long long>>a(k);
        for(int i=0;i<k;i++)cin>>a[i].first>>a[i].second;
        cout<<solve(k,n,m,p,q,a)<<"\n";
    }
}

int main(){
    read_your_input();
}
