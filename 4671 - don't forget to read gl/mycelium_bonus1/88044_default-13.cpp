#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// typedef int ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<vll> vvl;
typedef pair<ll, ll> pll;

#define sp << " " <<
#define debug(x) cout << x << endl
#define sz(x) (ll)(x.size())

const ll MOD=1e9+7;
const ll MOD1=998244353;
const ll INF=1e9;
const ll BIG=1e18;
const ll MX=2e5+5;
const double PI=acos(-1);

ll x8[8]={-1, -1, -1, 0, 0, 1, 1, 1};
ll y8[8]={-1, 0, 1, -1, 1, -1, 0, 1};
ll x4[4]={-1, 0, 0, 1};
ll y4[4]={0, 1, -1, 0};

void solve() {
    ll xg, yg, xm, ym;
    cin >> xg >> yg >> xm >> ym;
    xg+=500;
    yg+=500;
    xm+=500;
    ym+=500;
    ll mx=1200, mt=3005; // change if tle or too small
    vector<vector<pll>> lg(mt), lm(mt); // grass/mycelium based on time
    vector<vector<bool>> vis(mx, vector<bool>(mx, false)); // if desperate try bitset
    lg[0].push_back({xg, yg});
    lm[0].push_back({xm, ym});
    ll out=0;
    // cerr << "!\n";
    for (ll ct=0; ct<mt; ct++) {
        for (auto &[x, y]:lg[ct]) {
            if (vis[x][y]) continue;
            vis[x][y]=true;
            if (ct+2<mt) {
                for (ll i=0; i<4; i++) {
                    ll dx=x+x4[i], dy=y+y4[i];
                    if (dx<0 || dy<0 || dx>=mx || dy>=mx) continue;
                    lg[ct+2].push_back({dx, dy});
                }
            }
        }
        for (auto &[x, y]:lm[ct]) {
            if (vis[x][y]) continue;
            vis[x][y]=true; out++;
            if (ct+7<mt) {
                for (ll i=0; i<4; i++) {
                    ll dx=x+x4[i], dy=y+y4[i];
                    if (dx<0 || dy<0 || dx>=mx || dy>=mx) continue;
                    lm[ct+7].push_back({dx, dy});
                }
            }
        }
    }
    // cerr << "!\n";
    cout << out << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll tc=1;
    cin >> tc;
    while (tc--) {
        // cerr << tc << "\n";
        solve();
    }
}