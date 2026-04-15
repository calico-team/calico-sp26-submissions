#include <bits/stdc++.h>
using namespace std;

#define int long long

int modexp(int a, int b, int m) {
    int r = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) r = r * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return r;
}

int inv(int a, int m) {
    int b = m, u = 1, v = 0;
    while (b) {
        int t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

// n,m rp
int crt(int a, int b, int n, int m) {
    int l = lcm(n, m);
    return (a * m % l * inv(m, n) % l + b * n % l * inv(n, m) % l) % l;
}

void solve() {
    int k, n, m, p, q;
    cin >> k >> n >> m >> q >> p;
    int gn = gcd(p, n), gm = gcd(q, m);
    n /= gn, p /= gn;
    m /= gm, q /= gm;
    vector<int> x(k), y(k);
    for (int i = 0; i < k; i++) {
        cin >> x[i] >> y[i];
    }
    int pi = inv(p, n), qi = inv(q, m);

    // solve
    int x0 = x[0] / gn, y0 = y[0] / gm;
    int ans = 1e18, id = -1;
    for (int i = 0; i < k; i++) {
        if (x[i] % gn != x[0] % gn) continue;
        if (y[i] % gm != y[0] % gm) continue;
        int xi = x[i] / gn, yi = y[i] / gm;
        int a = (n + xi - x0) * pi % n;
        int b = (m + yi - y0) * qi % m;

        int g = gcd(n, m);
        if (a % g != b % g) continue;

        int t = (a % g) + crt(a/g, b/g, n/g, m/g);
        if (t == 0) t += lcm(n, m);
        if (t < ans) ans = t, id = i;
    }
    cout << id << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}