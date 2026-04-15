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

void solve() {
    ll k, n, m, p, q;
    cin >> k >> n >> m >> p >> q;
    vll x(k+1), y(k+1);
    map<pll, ll> ma;
    for (ll i=1; i<=k; i++) {cin >> x[i] >> y[i]; ma[{x[i], y[i]}]=i;}
    ll sx=x[1], sy=y[1];
    while (true) {
        sx+=q; sy+=p;
        if (sx>=n) sx-=n;
        if (sy>=m) sy-=m;
        if (sx<0) sx=n-sx;
        if (sy<0) sy=m-sy;
        if (ma[{sx, sy}]) {cout << ma[{sx, sy}]-1 << "\n"; return;}
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll tc=1;
    cin >> tc;
    while (tc--) {
        solve();
    }
}