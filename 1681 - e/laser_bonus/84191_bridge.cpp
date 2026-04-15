#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef long long ll;

int exgcd(int a, int b, int &x, int &y) {
    if (!b) { x = 1; y = 0; return a; }
    int x1, y1;
    int g = exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

pair<int, int>f(int q, int d, int n) {
    d = (d % n + n) % n;
    int x, y;
    int g = exgcd(q, n, x, y);
    if (d % g != 0) return {-1, -1};
    int mod = n / g;
    int t = x * (d / g) % mod;
    if (t < 0) t += mod;
    return {t, mod};
}

int merge(int a1, int m1, int a2, int m2) {
    if (a1 == -1 || a2 == -1) return -1;
    int x, y;
    int g = exgcd(m1, m2, x, y);
    if ((a2 - a1) % g != 0) return -1;
    int mod = m2 / g;
    int lcm = m1 / g * m2; 
    int t = ((a2 - a1) / g) * x % mod;
    if (t < 0) t += mod;
    int res = (a1 + m1 * t) % lcm;
    return res;
}

void solve()
{
    int k , n, m , p, q; cin>>k>>n>>m>>p>>q;
    vector<pair<int,int>>v(k);
    for(int i =0;i<k;i++)cin>>v[i].first >> v[i].second;
    int best = INF;
    int ans = 0;
    for(int i=1;i<k;i++){
        int dx = v[i].first - v[0].first;
        int dy = v[i].second - v[0].second;
        auto r1 = f(q, dx, n);
        auto r2 = f(p, dy, m);
        int xx = merge(r1.first, r1.second, r2.first, r2.second);
        if (xx != -1 && xx < best) {
            best = xx;
            ans = i;
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}