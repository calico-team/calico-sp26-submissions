#include<bits/stdc++.h>
// #define int ll
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

constexpr int V=2000;
constexpr int d[5]={0,1,0,-1,0};

bool v[V*2+2][V*2+2];

void solve(){
    int x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    queue<pair<pii,int>>q1,q2;
    q1.push(mkp(mkp(x1,y1),0));
    q2.push(mkp(mkp(x2,y2),0));
    memset(v,0,sizeof v);
    v[x1+V][y1+V]=1,v[x2+V][y2+V]=1;
    int ans=0;
    while(!q2.empty()){
        int flg=q1.front().se+2<=q2.front().se+7;
        int x,y,t;
        auto&&q=flg?q1:q2;
        x=q.front().fi.fi,y=q.front().fi.se,t=q.front().se;
        // cout<<flg<<' '<<x<<' '<<y<<' '<<t<<'\n';
        ans+=!flg;
        q.pop();
        for(int i=0;i<4;i++){
            int xx=x+d[i],yy=y+d[i+1];
            if(xx<-V||yy<-V||xx>V||yy>V||v[xx+V][yy+V])continue;
            v[xx+V][yy+V]=1;
            q.push(mkp(mkp(xx,yy),t+(flg?2:7)));
        }
    }
    cout<<ans<<'\n';
}

signed main(){
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}