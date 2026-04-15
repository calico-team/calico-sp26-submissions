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
int gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int g = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}
int mod_inv(int a, int m) {
    int x, y;
    int g = gcd(a, m, x, y);
    if (g != 1) return -1;
    x %= m;
    if (x < 0) x += m;
    return x;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int k, n, m, p, q;
        cin >> k >> n >> m >> p >> q;
        vector<pair<int,int>> v(k);
        for (int i = 0; i < k; i++) {
            cin >> v[i].first >> v[i].second;
        }
        int sx = v[0].first;
        int sy = v[0].second;
        long long best_t = (long long)4e18;
        int ans_idx = -1;
        for (int i = 0; i < k; i++) {
            int tx = v[i].first;
            int ty = v[i].second;
            int dx = (tx - sx) % n;
            if (dx < 0) dx += n;
            int dy = (ty - sy) % m;
            if (dy < 0) dy += m;
            int x1, y1;
            int gq = gcd(q, n, x1, y1);
            if (dx % gq != 0) continue;
            int x2, y2;
            int gp = gcd(p, m, x2, y2);
            if (dy % gp != 0) continue;
            int mod_x = n / gq;
            int mod_y = m / gp;
            int inv_q = mod_inv(q / gq, mod_x);
            if (inv_q == -1) continue;
            int step_x = (dx / gq) % mod_x;
            step_x = (step_x * inv_q) % mod_x;
            int inv_p = mod_inv(p / gp, mod_y);
            if (inv_p == -1) continue;
            int step_y = (dy / gp) % mod_y;
            step_y = (step_y * inv_p) % mod_y;
            int A, B;
            int g = gcd(mod_x, mod_y, A, B);
            if ((step_y - step_x) % g != 0) continue;
            int lcm = (mod_x / g) * mod_y;
            int diff = (step_y - step_x) / g;
            int k_mult = (diff * A) % (mod_y / g);
            if (k_mult < 0) k_mult += (mod_y / g);
            int t = step_x + mod_x * k_mult;
            t %= lcm;
            if (t < 0) t += lcm;
            if (t == 0) t = lcm;
            if (t < best_t) {
                best_t = t;
                ans_idx = i;
            }
        }
        cout << ans_idx << endl;
    }
}

