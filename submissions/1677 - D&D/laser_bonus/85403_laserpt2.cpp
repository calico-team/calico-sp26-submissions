#include <bits/stdc++.h>
using namespace std;

long long exgcd(long long a,long long b,long long &x,long long &y){
    if(!b){x=1;y=0;return a;}
    long long x1,y1,g=exgcd(b,a%b,x1,y1);
    x=y1;
    y=x1-a/b*y1;
    return g;
}

bool crt(long long a1,long long m1,long long a2,long long m2,long long &r,long long &lcm){
    long long x,y;
    long long g=exgcd(m1,m2,x,y);
    long long diff=a2-a1;
    if(diff%g!=0) return false;
    long long m2g=m2/g;
    long long k=( (__int128)diff/g * (x%m2g+m2g)%m2g )%m2g;
    r=a1 + m1*k;
    lcm = m1/g*m2;
    r%=lcm;
    if(r<0) r+=lcm;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin>>T;
    while(T--){
        long long K,N,M,P,Q;
        cin>>K>>N>>M>>P>>Q;
        vector<long long> X(K),Y(K);
        for(int i=0;i<K;i++) cin>>X[i]>>Y[i];

        long long x0=X[0],y0=Y[0];

        long long gq=__gcd(Q,N);
        long long gp=__gcd(P,M);
        long long n1=N/gq;
        long long m1=M/gp;
        long long gnm=__gcd(n1,m1);
        long long period = n1/gnm*m1;

        long long bestT=-1;
        int bestIdx=-1;

        for(int i=0;i<K;i++){
            long long dx = (X[i]-x0)%N;
            if(dx<0) dx+=N;
            long long dy = (Y[i]-y0)%M;
            if(dy<0) dy+=M;

            if(dx%gq!=0 || dy%gp!=0) continue;

            long long a1,mod1=n1;
            {
                long long dx1=dx/gq;
                long long q1=Q/gq;
                long long x,y;
                long long g=exgcd(q1,mod1,x,y);
                (void)g;
                long long inv=(x%mod1+mod1)%mod1;
                a1 = ( (__int128)dx1 * inv )%mod1;
            }

            long long a2,mod2=m1;
            {
                long long dy1=dy/gp;
                long long p1=P/gp;
                long long x,y;
                long long g=exgcd(p1,mod2,x,y);
                (void)g;
                long long inv=(x%mod2+mod2)%mod2;
                a2 = ( (__int128)dy1 * inv )%mod2;
            }

            long long t,lcm;
            if(!crt(a1,mod1,a2,mod2,t,lcm)) continue;

            if(t==0) t=period;
            if(bestT==-1 || t<bestT || (t==bestT && i<bestIdx)){
                bestT=t;
                bestIdx=i;
            }
        }

        cout<<bestIdx;
        if(T) cout<<"\n";
    }
}