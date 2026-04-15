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

int n;
int a[100100];
int f[100100][7];
int val[100010][7];

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n==1)cout<<a[1]<<'\n';
    if(n==2)cout<<a[1]<<' '<<a[2]<<'\n';
    if(n==3){
        int tmp=a[1]+a[2]+a[3]-max({a[1],a[2],a[3]})-min({a[1],a[2],a[3]});
        cout<<a[1]<<' '<<tmp<<' '<<a[3]<<'\n';
    }
}

signed main(){
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}