#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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
    xg+=700;
    yg+=700;
    xm+=700;
    ym+=700;
    ll mx=1500; // change if tle or too small
    vector<vector<bool>> vis(mx, vector<bool>(mx, false));
    set<array<ll, 4>> s; // {time, grass=0/mycelium=1, x, y} (change to pq if tle)
    s.insert({0, 0, xg, yg});
    s.insert({0, 1, xm, ym});
    ll out=0;
    // cerr << "!\n";
    while (!s.empty()) {
        auto [t, ti, x, y]=*s.begin();
        s.erase(s.begin());
        if (vis[x][y]) continue;
        vis[x][y]=true;
        if (ti) out++;
        for (ll i=0; i<4; i++) {
            ll dx=x+x4[i], dy=y+y4[i];
            if (dx<0 || dy<0 || dx>=mx || dy>=mx) continue;
            if (!vis[dx][dy]) s.insert({t+(ti?7:2), ti, dx, dy});
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