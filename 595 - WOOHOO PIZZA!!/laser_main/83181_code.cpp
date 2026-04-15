/*
*/

#include <bits/stdc++.h>
#define int long long
#define setmax(a, b) a = std::max(a,b);
#define setmin(a, b) a = std::min(a,b);
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = a; i >= (b); --i)
const int INF = std::numeric_limits<int>::max()/20;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        int k,n,m,p,q; cin >> k >> n >> m >> p >> q;
        map<array<int,2>, int> mp;
        set<array<int,2>> se;
        int X=-1,Y=-1;
        rep(i,0,k) {
            int x,y; cin >> x >> y; mp[{x,y}] = i;
            se.insert({x,y});
            if (X==-1) {X=x,Y=y;}
        }
        // cout << X << " " << Y << '\n';
        X += q;
        Y += p;
        X%=n;
        Y%=m;
        while (true) {
            if (se.count({X,Y})) {
                cout << mp[{X,Y}] << '\n';
                break;
            }
            X += q;
            Y += p;
            X%=n;
            Y%=m;
        }
    }   

    return 0;
}