#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;

ll inv(ll a, ll m) {
    return a <= 1 ? a : m - inv(m % a, a) * m / a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ll k, n, m, p, q;
        cin >> k >> n >> m >> p >> q;
        swap(p, q);

        vector<pll> points(k);
        for (int idx = 0; idx < k; idx++) {
            ll i, j;
            cin >> i >> j;

            points[idx] = {i, j};
        }

        if (n < m) {
            swap(n, m);
            swap(p, q);
            for (auto &[i, j] : points) {
                swap(i, j);
            }
        }

        ll i1 = (points[0].first + p) % n, j1 = (points[0].second + q) % m;
        ll nGcd = gcd(n, p), mGcd = gcd(m, q);
        ll ng = n / nGcd, mg = m / mGcd;
        ll dd = ng % mg;

        ll dGcd = gcd(mg, dd);
        ll rounds = mg / dGcd;

        ll invP = inv(p / nGcd, ng), invQ = inv(q / mGcd, mg);
        ll invD = inv(dd / dGcd, mg / dGcd);
        ll ans = LLONG_MAX, ansIdx = -1;
        for (int idx = 0; idx < k; idx++) {
            auto [i, j] = points[idx];
            if ((i - i1) % nGcd != 0 || (j - j1) % mGcd != 0) continue;
            ll ip = ((i - i1) / nGcd * invP % ng + ng) % ng;
            ll jp = ((j - j1) / mGcd * invQ % mg + mg) % mg;
            ll delta = ((jp - ip) % mg + mg) % mg;

            if (delta % dGcd != 0) continue;
            ll rIdx = delta / dGcd * invD % rounds;

            ll curr = rIdx * ng + ip;
            if (curr < ans) {
                ans = curr;
                ansIdx = idx;
            }
        }

        cout << ansIdx << '\n';
    }
}