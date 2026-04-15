/*******************
* what  the  sigma *
********************/
#include <iostream>
#include <vector>
#include <map>
#include <chrono>
#include <set>
#include <queue>
#include <algorithm>
#include <stack>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(x) tree<x, null_type, less<x>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;
#define lgm cin.tie(0)->sync_with_stdio(0);
#define be(x) x.begin(),x.end()
#define ve vector
#define ll long long
#define ld long double
bool enabledb=0;
#define DB(CODE) cout<<'\t'<<CODE<<endl;
#define SP <<' '<<
#define ull unsigned ll
#define f first
#define s second
#define pii pair<int, int>
#define tii tuple<int,int,int>
#define pll pair<ll,ll>
#define tll tuple<ll,ll,ll>
#define sz(x) ((int)x.size())
#define pb push_back
const ll mod = 1e9+7,maxn=200005;
const ll INF=(ll)9e18;
pll divide(pll a,ll t) {
    return {a.f,a.s*t};
}
pll ad(ll p1,ll q1,ll p2,ll q2) {
    return {(p1*q2+p2*q1),(q1*q2)};
}
pll add(pll a,pll b) {
    auto [p1,q1]=a;
    auto [p2,q2]=b;
    auto [p,q]=ad(p1,q1,p2,q2);
    return {p/__gcd(p,q),q/__gcd(p,q)};
}
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n >> m;
        ve<string> s(n);
        for (int i=0;i<n;i++) {
            cin >> s[i];
        }
        int x0=-1,y0=-1;
        for (int i=0;i<m;i++) {
            if (s[0][i]=='^') {
                x0=0,y0=i;
                break;
            }
            if (s[n-1][i]=='v') {
                x0=n-1,y0=i;
                break;
            }
        }
        if (x0==-1) {
            for (int i=0;i<n;i++) {
                if (s[i][0]=='<') {
                    x0=i,y0=0;
                    break;
                }
                if (s[i][m-1]=='>') {
                    x0=i,y0=m-1;
                    break;
                }
            }
        }
        if (x0==-1 && y0==-1) {
            cout << 0 << ' ' << 1 << '\n';
            continue;
        }
        ve<ve<int>> deg(n,ve<int>(m));
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (i>0&&s[i-1][j]!='v'&&s[i-1][j]!='.') deg[i][j]++;
                if (i<n-1&&s[i+1][j]!='^'&&s[i+1][j]!='.') deg[i][j]++;
                if (j>0&&s[i][j-1]!='>'&&s[i][j-1]!='.') deg[i][j]++;
                if (j<m-1&&s[i][j+1]!='<'&&s[i][j+1]!='.') deg[i][j]++;
            }
        }
        ve<ve<pll>> val(n,ve<pll>(m,pll{0ll,1ll}));
        ve<ve<bool>> vis(n,ve<bool>(m));

        int src=0;
        function<pll(int,int,ve<ve<pll>>&,int&)> f=[&](int x,int y,ve<ve<pll>>&val,int&src)->pll {
            if (x<0||x>=n||y<0||y>=m||s[x][y]=='.') return {0,1};
            if (vis[x][y]) return val[x][y];
            vis[x][y]=1;
            pll cur={0,1};
            bool found=0;
            if (x>0&&(s[x-1][y]=='v'||(s[x-1][y]=='S'&&s[x][y]!='^'))) {
                found=1;
                if (s[x-1][y]=='v') {
                    cur=add(cur,f(x-1,y,val,src));
                } else {
                    cur=add(cur,divide(f(x-1,y,val,src),deg[x-1][y]));
                }
            }
            if (x<n-1&&(s[x+1][y]=='^'||(s[x+1][y]=='S'&&s[x][y]!='v'))) {
                found=1;
                if (s[x+1][y]=='^') {
                    cur=add(cur,f(x+1,y,val,src));
                } else {
                    cur=add(cur,divide(f(x+1,y,val,src),deg[x+1][y]));
                }
            }
            if (y>0&&(s[x][y-1]=='>'||(s[x][y-1]=='S'&&s[x][y]!='<'))) {
                found=1;
                if (s[x][y-1]=='>') {
                    cur=add(cur,f(x,y-1,val,src));
                } else {
                    cur=add(cur,divide(f(x,y-1,val,src),deg[x][y-1]));
                }
            }
            if (y<m-1&&(s[x][y+1]=='<'||(s[x][y+1]=='S'&&s[x][y]!='>'))) {
                found=1;
                if (s[x][y+1]=='<') {
                    cur=add(cur,f(x,y+1,val,src));
                } else {
                    cur=add(cur,divide(f(x,y+1,val,src),deg[x][y+1]));
                }
            }
            if (!found) {
                src++;
                return val[x][y]={1,1};
            }
            return val[x][y]=cur;
        };
        pll ans=f(x0,y0,val,src);
        if (src==0) src=1;
        ans=divide(ans,src);
        cout << ans.f/__gcd(ans.f,ans.s) << ' ' << ans.s/__gcd(ans.f,ans.s) << '\n';
    }
}