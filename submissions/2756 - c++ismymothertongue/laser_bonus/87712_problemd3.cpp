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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cout.tie(nullptr);
    int T;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        int k, n, m, p, q;
        cin >> k >> n >> m >> p >> q;
        vector<pair<int,int>> v(k);
        for (int i = 0; i < k; i++) {
            cin >> v[i].fi >> v[i].se;
        }
        int sx = v[0].fi;
        int sy = v[0].se;
        int best_t = INT_MAX;
        int ans_idx = -1;
        for (int i = 0; i < k; i++) {
            int tx = v[i].fi;
            int ty = v[i].se;
            int dx = (tx - sx) % n;
            if (dx < 0) {
                dx += n;
            }
            int dy = (ty - sy) % m;
            if (dy < 0) {
                dy += m;
            }
            int x1, y1, x2, y2;
            int gq = gcd(q, n, x1, y1);
            int gp = gcd(p, m, x2, y2);
            if (dx % gq != 0 || dy % gp != 0) {
                continue;
            }
            int mod_x = n / gq;
            int mod_y = m / gp;
            int a1, b1;
            gcd(q / gq, mod_x, a1, b1);
            int inv_q = a1 % mod_x;
            if (inv_q < 0) {
                inv_q += mod_x;
            }
            int step_x = ((dx / gq) * inv_q) % mod_x;
            int a2, b2;
            gcd(p / gp, mod_y, a2, b2);
            int inv_p = a2 % mod_y;
            if (inv_p < 0) {
                inv_p += mod_y;
            }
            int step_y = ((dy / gp) * inv_p) % mod_y;
            int A, B;
            int g = gcd(mod_x, mod_y, A, B);

            if ((step_y - step_x) % g != 0) {
                continue;
            }
            int lcm = (mod_x / g) * mod_y;
            int diff = (step_y - step_x) / g;
            int k_mult = (diff * A) % (mod_y / g);
            if (k_mult < 0) {
                k_mult += (mod_y / g);
            }
            int t = step_x + mod_x * k_mult;
            t %= lcm;
            if (t < 0) {
                t += lcm;
            }
            if (t == 0) {
                t = lcm;
            }
            if (t < best_t) {
                best_t = t;
                ans_idx = i;
            }
        }
        cout << ans_idx << endl;
    }
}
