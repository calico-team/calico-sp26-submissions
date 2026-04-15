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
    ll n, p, r, k;
    cin >> n >> p >> r >> k;
    for (ll i=1; i<=n; i++) {
        ll c;
        cin >> c;
        p-=c;
        if (!(i%k) && p>=0) p+=r;
    }
    cout << (p<0?"nah id lose":"nah id win") << "\n";
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