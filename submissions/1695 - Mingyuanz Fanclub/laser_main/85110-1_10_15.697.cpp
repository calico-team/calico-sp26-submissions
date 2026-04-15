#include <bits/stdc++.h>
#define int long long

using namespace std;

int gcd(int a, int b, int &x, int &y){
    if(!b) return x = 1, y = 0, a;
    int x1, y1, d = gcd(b, a%b, x1, y1);
    return x = y1, y = x1 - (a / b) * y1, d;
}

pair<int, int> find(int d, int v, int mod){
    int x, y, g = gcd(v, mod, x, y), m = mod / g;
    if(d%g) return {-1, -1};
    int res = (d / g)%m * (x%m)%m;
    if(res < 0) return {res + m, m};
    else return {res, m};
}

void solve(){
    int k, n, m, p, q, ans = -1, mn = 1e18; cin >> k >> n >> m >> p >> q;
    vector<pair<int, int>> a(k + 1);
    for(int i = 1; i <= k; ++i) cin >> a[i].first >> a[i].second;
    for(int i = 1; i <= k; ++i){
        auto [tx, mx] = find((a[i].first - a[1].first + n)%n, q, n);
        auto [ty, my] = find((a[i].second - a[1].second + m)%m, p, m);
        if(tx == -1 || ty == -1) continue;
        int x, y, g = gcd(mx, my, x, y), inv = my / g;
        if((ty - tx)%g) continue;
        int K = ((ty - tx) / g%inv + inv)%inv * ((x%inv + inv)%inv)%inv;
        int inv2 = mx / g * my, t = (tx + K * mx)%inv2;
        if(t <= 0) t += inv2;
        if(t < mn) mn = t, ans = i;
    }
    cout << ans - 1 << "\n";
}

int32_t main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
}