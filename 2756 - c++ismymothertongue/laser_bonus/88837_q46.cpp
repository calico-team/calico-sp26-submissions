#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX LLONG_MAX
#define MIN LLONG_MIN
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define pf push_front
const int mod = 1e9 + 7;
typedef __int128_t int128;
int gcd(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int g = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return g;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int k, n, m, p, q;
        cin >> k >> n >> m >> p >> q;
        vector<pair<int,int>> v(k);
        for (int i = 0; i < k; i++) {
            cin >> v[i].fi >> v[i].se;
        }
        int sx = v[0].fi;
        int sy = v[0].se;
        int ans = -1;
        int128 best = -1;
        for (int i = 0; i < k; i++) {
            int x = v[i].fi;
            int y = v[i].se;
            int dx = (x - sx % n + n) % n;
            int dy = (y - sy % m + m) % m;
            int x1, y1;
            int gq = gcd(q, n, x1, y1);
            if (dx % gq != 0) continue;
            int stepx = (int128)(dx / gq) * (x1 % (n / gq)) % (n / gq);
            if (stepx < 0) stepx += (n / gq);
            int x2, y2;
            int gp = gcd(p, m, x2, y2);
            if (dy % gp != 0) continue;
            int stepy = (int128)(dy / gp) * (x2 % (m / gp)) % (m / gp);
            if (stepy < 0) stepy += (m / gp);
            int mx = n / gq;
            int my = m / gp;
            int a1, b1;
            int gc = gcd(mx, my, a1, b1);
            if ((stepy - stepx) % gc != 0) continue;
            int128 lcm = (int128)mx * (my / gc);
            int128 diff = (stepy - stepx) / gc;
            int128 k2 = (diff * a1) % (my / gc);
            if (k2 < 0) k2 += (my / gc);
            int128 tsteps = stepx + (int128)mx * k2;
            tsteps %= lcm;
            if (tsteps < 0) tsteps += lcm;
            if (tsteps == 0 && i == 0) tsteps = lcm;
            if (best == -1 || tsteps < best) {
                best = tsteps;
                ans = i;
            }
        }
        cout << ans << endl;
    }
}
