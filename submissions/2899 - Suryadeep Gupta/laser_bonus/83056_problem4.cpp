#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int K;
        ll N, M, P, Q;
        cin >> K >> N >> M >> P >> Q;

        vector<pair<ll,ll>> ast(K);
        unordered_map<ll, int> mp;
        mp.reserve(K * 2);

        for (int i = 0; i < K; i++) {
            cin >> ast[i].first >> ast[i].second;
            ll key = ast[i].first * (ll)1e7 + ast[i].second;
            mp[key] = i;
        }

        ll x0 = ast[0].first;
        ll y0 = ast[0].second;

        ll x = x0, y = y0;

        ll lazarbeam = 0;

        ll g1 = gcd(Q, N);
        ll g2 = gcd(P, M);

        ll period_x = N / g1;
        ll period_y = M / g2;

        ll L = lcm(period_x, period_y);

        for (ll t = 1; t <= L; t++) {
            x = (x + Q) % N;
            y = (y + P) % M;

            ll key = x * (ll)1e7 + y;
            if (mp.find(key) != mp.end()) {
                cout << mp[key] << "\n";
                break;
            }
        }
    }

    return 0;
}

void read_your_input() {}