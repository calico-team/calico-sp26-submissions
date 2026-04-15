#include <bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using lli=long long int;
using pii=pair<int, int>;
using plli=pair<lli, lli>;
using vlli=vector<lli>;
using vpii=vector<pii>;
using vplli=vector<plli>;
using vvi=vector<vi>;
using vvlli=vector<vlli>;
using vc=vector<char>;
using vvc=vector<vc>;
using vb=vector<bool>;
using vvb=vector<vector<bool>>;

int inv(int a, int mod){
    for (int i=0; i<mod; ++i){
        if (((lli)i*a)%mod==1) return i;
    }
    return 0;
}

lli solve(int a1, int m1, int a2, int m2){
    for (lli i=(a1==0 ? m1 : a1); i<=(lli)m1*m2; i+=m1){
        if (i%m2==a2) return i;
    }
    return 1e18;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--){
        int k, n, m, q, p;
        cin >> k >> n >> m >> q >> p;
        vpii A(k);
        for (int i=0; i<k; ++i){
            int x, y;
            cin >> x >> y;
            A[i]={x, y};
        }
        int a=A[0].first, b=A[0].second;
        vlli ans(k, 1e18);
        for (int i=1; i<k; ++i){
            // a+pt=A[i].first mod n
            // pt=A[i].first-a mod n
            int c=(A[i].first-a+n)%n;
            int d=(A[i].second-b+m)%m;
            // tp=c mod n
            // tq=d mod m
            int n1=n, m1=m;
            int p1=p, q1=q;
            if (c%gcd(p, n)!=0) continue;
            if (d%gcd(q, m)!=0) continue;
            int g=gcd(p, n);
            p1/=g, n1/=g, c/=g;
            g=gcd(q, m);
            q1/=g, m1/=g, d/=g;
            int x=inv(p1, n1);
            int y=inv(q1, m1);
            if (x==0 && c!=0) continue;
            if (y==0 && d!=0) continue;
            if (x==0 && y==0){
                ans[i]=1;
                continue;
            }
            if (x==0){
                y=((lli)d*y)%m1;
                ans[i]=(y==0 ? m1 : y);
                continue;
            }
            if (y==0){
                x=((lli)c*x)%n1;
                ans[i]=(x==0 ? n1 : x);
                continue;
            }
            x=((lli)c*x)%n1;
            y=((lli)d*y)%m1;
            lli t=solve(x, n1, y, m1);
            ans[i]=t;
        }
        int ind=0;
        for (int i=1; i<k; ++i){
            if (ans[i]<ans[ind]) ind=i;
        }
        cout << ind << endl;
    }
}