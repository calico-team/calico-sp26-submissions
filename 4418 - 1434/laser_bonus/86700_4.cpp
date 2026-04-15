#include <bits/stdc++.h>
using namespace std;
#define int long long

int modexp(int base, int exp, int mod) {
    int res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    res %= mod;
    return res;
}

int phi(int n) {
    int res = n;
    for (int p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            while (n % p == 0) n /= p;
            res -= res / p;
        }
    }
    if (n > 1) res -= res / n;
    return res;
}

int inv(int base, int mod) {
    return modexp(base, phi(mod) - 1, mod);
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int k, n, m, p, q;
        cin >> k >> n >> m >> p >> q;
        vector <pair <int, int>> asteroids;
        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            asteroids.push_back({x, y});
        }
        int cx = asteroids[0].first, cy = asteroids[0].second;
        int tt = LONG_LONG_MAX;
        int ans = 0;
        for (int i = 0; i < k; i++) {
            int dx = (asteroids[i].first - asteroids[0].first + n) % n;
            int dy = (asteroids[i].second - asteroids[0].second + m) % m;
            int gn = gcd(q, n), gm = gcd(p, m);
            if (dx % gn || dy % gm) continue;
            int tq = 0, tp = 0;
            int nn = n / gn, mm = m / gm;
            if (n != gn) tq = dx / gn * inv(q / gn, nn) % (nn);
            if (m != gm) tp = dy / gm * inv(p / gm, mm) % (mm);
            int g = gcd(nn, mm);
            if (tp % g != tq % g) continue;
            int idk = m / gm / g;
            int add = 0;
            if (idk != 1) {
                add = (((tp - tq) / g) % idk + idk) % idk * inv(nn / g, idk) % idk;
            }
            int time = (tq + nn * add) % (nn / g * mm);
            if (time == 0) time = nn / g * mm;
            if (time < tt) {
                tt = time;
                ans = i;
            }
        }
        cout << ans << endl;
    }
}