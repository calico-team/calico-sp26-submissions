#include<bits/stdc++.h>
#define int ll
using namespace std;

#define all(a) (a).begin(),(a).end()
#define mkp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define LB lower_bound

using ll=long long;
using ull=unsigned long long;
using i128=__int128;
using u128=unsigned __int128;
using ld=long double;
using vi=vector<int>;
using pii=pair<int,int>;
using vpi=vector<pii>;

template<typename _T1,typename _T2>
inline bool chkmin(_T1&x,const _T2&y){if(y<x)return x=y,1;else return 0;}
template<typename _T1,typename _T2>
inline bool chkmax(_T1&x,const _T2&y){if(y>x)return x=y,1;else return 0;}

int k,n,m,x,y;
int a[100100],b[100100];
int c[1000100],d[1000100];
int tmp[1000100];

void solve(){
    cin>>k>>n>>m>>y>>x;
    for(int i=0;i<k;i++)cin>>a[i]>>b[i];
    k--;
    for(int i=1;i<=k;i++)a[i]=(a[i]-a[0]+n)%n,b[i]=(b[i]-b[0]+m)%m;
    memset(c,-1,sizeof c);
    for(int i=0,j=0;!i||j;i++,j=(j+x)%n)c[j]=i;
    memset(d,-1,sizeof d);
    for(int i=0,j=0;!i||j;i++,j=(j+y)%m)d[j]=i;
    for(int i=1;i<=k;i++)a[i]=c[a[i]],b[i]=d[b[i]];
    n=n/__gcd(x,n);
    m=m/__gcd(y,m);
    int g=__gcd(n,m);
    pii ans=mkp(n*m/g,0);
    int nn=n/g,mm=m/g;
    int v1=0,v2=0;
    for(int i=1;i<=nn;i++)if(mm*i%nn==1)v1=i;
    for(int i=1;i<=mm;i++)if(nn*i%mm==1)v2=i;
    for(int i=1;i<=k;i++)if(a[i]>=0&&b[i]>=0&&a[i]%g==b[i]%g){
        int aa=a[i]/g,bb=b[i]/g;
        int tmp=(mm*v1*aa+nn*v2*bb)%(nn*mm);
        chkmin(ans,mkp(tmp*g+a[i]%g,i));
    }
    cout<<ans.se<<'\n';
}

signed main(){
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}