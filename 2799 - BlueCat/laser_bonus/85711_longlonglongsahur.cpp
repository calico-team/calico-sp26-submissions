#include<bits/stdc++.h>
using namespace std;

long long egcd(long long a,long long b,long long &x,long long &y){
    if(!b){
        x=1;
        y=0;
        return a;
    }
    long long x1,y1;
    long long g=egcd(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return g;
}
long long modinv(long long a,long long m){
    long long x,y;
    long long g=egcd(a,m,x,y);
    if(g!=1)return -1;
    x=(x%m+m)%m;
    return x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;

    while(t--){
        int k,n,m;
        long long p,q;
        cin>>k>>n>>m>>p>>q;

        vector<long long> x(k),y(k);
        for(int i=0;i<k;i++)cin>>x[i]>>y[i];

        long long x0=x[0],y0=y[0];

        long long best_t=LLONG_MAX;
        int best_i=0;

        long long g1=gcd(q,(long long)n);
        long long g2=gcd(p,(long long)m);

        long long n1=n/g1,q1=q/g1;
        long long m1=m/g2,p1=p/g2;

        long long invq=modinv(q1,n1);
        long long invp=modinv(p1,m1);

        for(int i=0;i<k;i++){
            long long dx=(x[i]-x0)%n;
            long long dy=(y[i]-y0)%m;

            if(dx<0)dx+=n;
            if(dy<0)dy+=m;

            if(dx%g1||dy%g2)continue;

            long long t1=(dx/g1)%n1;
            t1=(t1*invq)%n1;

            long long t2=(dy/g2)%m1;
            t2=(t2*invp)%m1;
            long long x,y;
            long long g=egcd(n1,m1,x,y);
            if((t2-t1)%g!=0)continue;

            long long mod=m1/g;
            long long k2=((t2-t1)/g)%mod;
            if(k2<0)k2+=mod;

            long long mul=(x%mod+mod)%mod;
            mul=(mul*k2)%mod;

            long long lcm=n1/g*m1;

            long long t=(t1+mul*n1)%lcm;
            if(t<0)t+=lcm;

            if(t==0)t=lcm;

            if(t<best_t){
                best_t=t;
                best_i=i;
            }
        }

        cout<<best_i<<"\n";
    }
}