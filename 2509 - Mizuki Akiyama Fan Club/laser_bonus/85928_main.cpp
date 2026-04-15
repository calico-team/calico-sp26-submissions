#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef long double ld;
#define f first
#define s second
#define pb push_back
#define endl "\n"

constexpr int mod = 998244353;

// https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp
// https://github.com/atcoder/ac-library/blob/master/atcoder/math.hpp

constexpr long long safe_mod(long long x, long long m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}

constexpr std::pair<long long, long long> inv_gcd(long long a, long long b) {
    a = safe_mod(a, b);
    if (a == 0) return {b, 0};

    // Contracts:
    // [1] s - m0 * a = 0 (mod b)
    // [2] t - m1 * a = 0 (mod b)
    // [3] s * |m1| + t * |m0| <= b
    long long s = b, t = a;
    long long m0 = 0, m1 = 1;

    while (t) {
        long long u = s / t;
        s -= t * u;
        m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b

        // [3]:
        // (s - t * u) * |m1| + t * |m0 - m1 * u|
        // <= s * |m1| - t * u * |m1| + t * (|m0| + |m1| * u)
        // = s * |m1| + t * |m0| <= b

        auto tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
    // by [3]: |m0| <= b/g
    // by g != b: |m0| < b/g
    if (m0 < 0) m0 += b / s;
    return {s, m0};
}

std::pair<long long, long long> crt(const std::vector<long long>& r,
                                    const std::vector<long long>& m) {
    assert(r.size() == m.size());
    int n = int(r.size());
    // Contracts: 0 <= r0 < m0
    long long r0 = 0, m0 = 1;
    for (int i = 0; i < n; i++) {
        assert(1 <= m[i]);
        long long r1 = safe_mod(r[i], m[i]), m1 = m[i];
        if (m0 < m1) {
            std::swap(r0, r1);
            std::swap(m0, m1);
        }
        if (m0 % m1 == 0) {
            if (r0 % m1 != r1) return {0, 0};
            continue;
        }
        // assume: m0 > m1, lcm(m0, m1) >= 2 * max(m0, m1)

        // (r0, m0), (r1, m1) -> (r2, m2 = lcm(m0, m1));
        // r2 % m0 = r0
        // r2 % m1 = r1
        // -> (r0 + x*m0) % m1 = r1
        // -> x*u0*g = r1-r0 (mod u1*g) (u0*g = m0, u1*g = m1)
        // -> x = (r1 - r0) / g * inv(u0) (mod u1)

        // im = inv(u0) (mod u1) (0 <= im < u1)
        long long g, im;
        std::tie(g, im) = inv_gcd(m0, m1);

        long long u1 = (m1 / g);
        // |r1 - r0| < (m0 + m1) <= lcm(m0, m1)
        if ((r1 - r0) % g) return {0, 0};

        // u1 * u1 <= m1 * m1 / g / g <= m0 * m1 / g = lcm(m0, m1)
        long long x = (r1 - r0) / g % u1 * im % u1;

        // |r0| + |m0 * x|
        // < m0 + m0 * (u1 - 1)
        // = m0 + m0 * m1 / g - m0
        // = lcm(m0, m1)
        r0 += x * m0;
        m0 *= u1;  // -> lcm(m0, m1)
        if (r0 < 0) r0 += m0;
    }
    return {r0, m0};
}

void solve() {
    int k, n, m, p, q;
    cin >> k >> n >> m >> p >> q;
    vector<pi> arr(k);
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        arr[i] = {x, y};
    }
    vector<ll> ind_x(n+1, -1);
    int x = arr[0].f;
    int j = 0;
    while (true) {
        ind_x[x] = j++;
        x += q;
        x %= n;
        if (x == arr[0].f) {
            break;
        }
    }
    vector<ll> ind_y(m+1, -1);
    j = 0;
    int y = arr[0].s;
    while (true) {
        ind_y[y] = j++;
        y += p;
        y %= m;
        if (y == arr[0].s) {
            break;
        }
    }
    ll m1 = n/gcd(n, q);
    ll m2 = m/gcd(m, p);
    vector<ll> time(k);
    for (int i = 0; i < k; i++) {
        int x = arr[i].f;
        int y = arr[i].s;
        if (ind_x[x] == -1 || ind_y[y] == -1) {
            time[i] = numeric_limits<ll>::max();
            continue;
        }
        pll res = crt({ind_x[x], ind_y[y]}, {m1, m2});
        if (res.f == 0 && res.s == 0) {
            time[i] = numeric_limits<ll>::max();
            continue;
        }
        time[i] = res.f;
    }
    time[0] += lcm(m1, m2);
    int mn = 0;
    for (int i = 0; i < k; i++) {
        if (time[i] < time[mn]) {
            mn = i;
        }
    }
    cout << mn << endl;
}

int main() {
    cin.tie(0);     
    ios_base::sync_with_stdio(0);
 
    int t = 1;
    cin >> t;
 
    for (int tc = 0; tc < t; tc++) {
        solve();
    }
 
    return 0;
}