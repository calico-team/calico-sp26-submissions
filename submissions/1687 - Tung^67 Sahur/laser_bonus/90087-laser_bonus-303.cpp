#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int k, n, m, p, q;
        cin >> k >> n >> m >> p >> q;
        swap(p, q);

        vector<pii> points(k);
        map<pii, vector<int>> diags;

        for (int idx = 0; idx < k; idx++) {
            int i, j;
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

        int i1 = (points[0].first + p) % n, j1 = (points[0].second + q) % m;
        int ng = n / gcd(n, p), mg = m / gcd(m, q);
        int dd = ng % mg;
        int rounds = mg / gcd(mg, dd);

        vector<int> iIdx(n, -1), jIdx(m, -1);
        for (int i = 0; i < ng; i++) {
            iIdx[((ll) i * p + i1) % n] = i;
        }
        for (int j = 0; j < mg; j++) {
            jIdx[((ll) j * q + j1) % m] = j;
        }

        vector<int> roundIdx(mg, -1);
        for (int i = 0; i < rounds; i++) {
            roundIdx[(ll) i * dd % mg] = i;
        }

        ll ans = LLONG_MAX, idx = -1;
        for (int x = 0; x < k; x++) {
            auto [i, j] = points[x];
            int ip = iIdx[i], jp = jIdx[j];
            int delta = (jp - ip + mg) % mg;
            if (ip == -1 || jp == -1 || roundIdx[delta] == -1) continue;
            ll curr = (ll) roundIdx[delta] * ng + ip;
            if (curr < ans) {
                ans = curr;
                idx = x;
            }
        }

        cout << idx << '\n';
    }
}