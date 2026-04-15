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

            int ct = min(i / p, j / q);
            diags[{i - ct * p, j - ct * q}].push_back(idx);
        }


        int i = (points[0].first + p) % n, j = (points[0].second + q) % m;

        while (true) {
            int ct = min(i / p, j / q);
            auto it = diags.find({i - ct * p, j - ct * q});
            if (it != diags.end()) {
                int minI = INT_MAX, minIdx = -1;
                for (int idx : it->second) {
                    int currI = points[idx].first;
                    if (currI >= i && currI < minI) {
                        minI = currI;
                        minIdx = idx;
                    }
                }

                if (minI != INT_MAX) {
                    cout << minIdx << '\n';
                    break;
                }
            }

            ct = min((n - i + p - 1) / p, (m - j + q - 1) / q);
            i = (i + ct * p) % n;
            j = (j + ct * q) % m;
        }
    }
}