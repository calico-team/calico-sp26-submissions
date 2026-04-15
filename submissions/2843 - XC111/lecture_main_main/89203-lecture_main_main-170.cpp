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

int a[1010][1010];
int n,m,k;
int b[2020][2020],c[2020][2020];

void solve(){
    cin>>n>>m>>k;
    int ccc=0;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
        char c;
        cin>>c;
        if(c=='-')ccc++,a[i][j]=1;
        else a[i][j]=0;
    }
    if(ccc<k)cout<<"wtf?\n";
    int nn=0;
    memset(b,0,sizeof b);
    memset(c,0,sizeof c);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
        int ii=j-i+n,jj=i+j-1;
        chkmax(nn,ii),chkmax(nn,jj);
        c[ii][jj]=b[ii][jj]=a[i][j];
    }
    for(int i=1;i<=nn;i++)for(int j=1;j<=nn;j++)b[i][j]+=b[i-1][j]+b[i][j-1]-b[i-1][j-1];
    auto check=[&](int d){
        int mx=0;
        for(int i=d;i<=nn;i++)for(int j=d;j<=nn;j++)chkmax(mx,b[i][j]-b[i-d][j]-b[i][j-d]+b[i-d][j-d]);
        return mx>=k;
    };
    int l=1,r=nn;
    while(l<r){
        int mid=(l+r)>>1;
        if(check(mid))r=mid;
        else l=mid+1;
    }
    vector<pii>vec;
    [&](){
        for(int i=l;i<=nn;i++)for(int j=l;j<=nn;j++)if(b[i][j]-b[i-l][j]-b[i][j-l]+b[i-l][j-l]>=k){
            for(int ii=i-l+1;ii<=i;ii++)for(int jj=j-l+1;jj<=j;jj++)if(c[ii][jj]&&vec.size()<k)vec.eb(ii,jj);
            return;
        }
    }();
    for(auto[x,y]:vec)cout<<(y-x+n+1)/2-1<<' '<<(x+y-n+1)/2-1<<'\n';
}

signed main(){
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}