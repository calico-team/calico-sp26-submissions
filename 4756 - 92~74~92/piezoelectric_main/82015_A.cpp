#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#ifdef _debug
#include </home/tonyz/templates/debug.cpp>
#else
#define debug(...) 42
#endif

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define pb push_back
#define vt vector
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define ub upper_bound
#define lb lower_bound


const int inf = (int)2e9, mod = (int)1e9 + 7, mx = (int)2e5 + 10;
const ll infll = (ll)7e18;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

void solve(){
    ll l, w, e, r; cin >> l >> w >> e >> r;
    ll p = 2 * (l + w);
    cout << (e) / (r * p) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}

