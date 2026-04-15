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
    ll n; cin >> n;
    vt<ll> a(n); for(auto &u : a)cin >> u;
    vector<vector<pll>> dp(n, vector<pll>(3));
    auto b = a; sort(all(b));
    vector<ll> meds; 
    if(n & 1){
        meds.pb(b[n/2]); meds.pb(b[n/2]); 
    }else{
        meds.pb(b[n/2]); meds.pb(b[n/2 - 1]);
    }
    dp[0][0] = {0, -1};
    dp[0][1] = {abs(a[0] - meds[0]), -1};
    dp[0][2] = {abs(a[0] - meds[1]), -1};
    for(int i = 1; i < n; i++){
       dp[i][0] = min({pll{dp[i-1][0].first + abs(a[i-1] - a[i]), 0LL}, {dp[i-1][1].first + abs(meds[0] - a[i]), 1LL}, {dp[i-1][2].first + abs(meds[1] - a[i]), 2LL}});
       dp[i][1] = min({pll{dp[i-1][0].first + abs(a[i-1] - meds[0]) + abs(a[i] - meds[0]), 0}, {dp[i-1][1].first + abs(a[i] - meds[0]), 1}, {dp[i-1][2].first + abs(a[i] - meds[0]) + abs(meds[0] - meds[1]), 2}});
       dp[i][2] = min({pll{dp[i-1][0].first + abs(a[i-1] - meds[1]) + abs(a[i] - meds[1]), 0}, {dp[i-1][1].first + abs(a[i] - meds[1]) + abs(meds[0] - meds[1]), 1}, {dp[i-1][2].first + abs(a[i] - meds[1]), 2}});
    }
    auto cur = min({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    vt<ll> res; int p = cur.second; 
    for(int i = n - 1; i >= 0; i--){
        if(p == 0)res.pb(a[i]);
        if(p == 1)res.pb(meds[0]);
        if(p == 2)res.pb(meds[1]);
        if(i != 0){
            p = dp[i][p].second; 
        }
    }
    reverse(all(res)); for(auto u : res)cout << u << " ";
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}

