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
signed main() {
    lgm;
    int t;
    cin >> t;
    while (t--) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        // bool positive=0;
        // if (a<c^b<d) positive=1;
        // int l=0,r=1e9;
        // while (l<=r) {
        //     int mid=(l+r)>>1;
        //     int pos1=
        // }
        // int dist=abs(a-c)+abs(b-d);
        vector<pii> grass={{a,b}};
        vector<pii> avail={{c,d}};
        map<pii,bool> dead;
        dead[{a,b}]=1;
        dead[{c,d}]=1;
        int ans=1;
        int tick=1;
        while (true) {
            if (tick%2==0) {
                vector<pii> grs2;
                swap(grs2,grass);
                for (auto [x,y]:grs2) {
                    if (!dead[{x+1,y}]) {
                        dead[{x+1,y}]=1;
                        grass.pb({x+1,y});
                    }
                    if (!dead[{x-1,y}]) {
                        dead[{x-1,y}]=1;
                        grass.pb({x-1,y});
                    }
                    if (!dead[{x,y+1}]) {
                        dead[{x,y+1}]=1;
                        grass.pb({x,y+1});
                    }
                    if (!dead[{x,y-1}]) {
                        dead[{x,y-1}]=1;
                        grass.pb({x,y-1});
                    }
                }
            }
            if (tick%7==0) {
                vector<pii> av2;
                swap(av2,avail);
                for (auto [x,y]:av2) {
                    if (!dead[{x+1,y}]) {
                        dead[{x+1,y}]=1;
                        avail.pb({x+1,y});
                        ans++;
                    }
                    if (!dead[{x-1,y}]) {
                        dead[{x-1,y}]=1;
                        avail.pb({x-1,y});
                        ans++;
                    }
                    if (!dead[{x,y+1}]) {
                        dead[{x,y+1}]=1;
                        avail.pb({x,y+1});
                        ans++;
                    }
                    if (!dead[{x,y-1}]) {
                        dead[{x,y-1}]=1;
                        avail.pb({x,y-1});
                        ans++;
                    }
                }
                if (avail.empty()) break;
            }
            tick++;
        }
        cout << ans << '\n';
    }
}   