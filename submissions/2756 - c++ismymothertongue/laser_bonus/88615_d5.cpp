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
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int k, n, m, p, q;
        cin >> k >> n >> m >> p >> q;
        vector<pair<int,int>> pts(k);
        for (int i = 0; i < k; i++) {
            cin >> pts[i].fi >> pts[i].se;
        }
        int sx = pts[0].fi;
        int sy = pts[0].se;
        int bestidx = -1;
        int besttime = -1;
        for (int i = 0; i < k; i++) {
            int tx = pts[i].fi;
            int ty = pts[i].se;
            int dx = (tx - (sx % n) + n) % n;
            int dy = (ty - (sy % m) + m) % m;
            int x, y;
            int gq = gcd(q, n, x, y);
            if (dx % gq != 0) continue;
            int stepx = (x * (dx / gq)) % (n / gq);
            if (stepx < 0) stepx += (n / gq);
            int gp = gcd(p, m, x, y);
            if (dy % gp != 0) continue;
            int stepy = (x * (dy / gp)) % (m / gp);
            if (stepy < 0) stepy += (m / gp);
            int modx = n / gq;
            int mody = m / gp;
            int inva, invb;
            int g = gcd(modx, mody, inva, invb);
            if ((stepy - stepx) % g != 0) continue;
            int lcm = (modx / g) * mody;
            int diff = (stepy - stepx) / g;
            int kmul = (diff * inva) % (mody / g);
            if (kmul < 0) kmul += (mody / g);
            int tval = stepx + modx * kmul;
            tval %= lcm;
            if (tval < 0) tval += lcm;
            if (tval == 0 && i == 0) tval = lcm;
            if (tval > 0 && (besttime == -1 || tval < besttime)) {
                besttime = tval;
                bestidx = i;
            }
        }
        cout << bestidx << endl;
    }
}
