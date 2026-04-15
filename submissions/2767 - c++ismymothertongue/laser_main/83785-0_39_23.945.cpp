#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll get_gcd(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = get_gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

void solve() {
    int K;
    ll N, M, P, Q;
    cin >> K >> N >> M >> P >> Q;

    vector<pair<ll, ll>> points(K);
    for (int i = 0; i < K; i++) {
        cin >> points[i].first >> points[i].second;
    }

    ll x0 = points[0].first;
    ll y0 = points[0].second;

    ll bestIndex = -1;
    ll minSteps = -1;

    for (int i = 0; i < K; i++) {
        ll x_target = points[i].first;
        ll y_target = points[i].second;

        ll x_diff = (x_target - x0 % N + N) % N;
        ll y_diff = (y_target - y0 % M + M) % M;

        ll x, y;
        ll gQ = get_gcd(Q, N, x, y);
        if (x_diff % gQ != 0) continue;
        ll tx = (x * (x_diff / gQ)) % (N / gQ);
        if (tx < 0) tx += (N / gQ);

        ll gP = get_gcd(P, M, x, y);
        if (y_diff % gP != 0) continue;
        ll ty = (x * (y_diff / gP)) % (M / gP);
        if (ty < 0) ty += (M / gP);

        ll modX = N / gQ;
        ll modY = M / gP;

        ll x_inv, y_inv;
        ll g_final = get_gcd(modX, modY, x_inv, y_inv);

        if ((ty - tx) % g_final != 0) continue;

        ll lcm = (modX * modY) / g_final;
        ll combined = (tx + modX * (((ty - tx) / g_final * x_inv) % (modY / g_final))) % lcm;
        if (combined < 0) combined += lcm;

        if (combined == 0 && i == 0) combined = lcm;

        if (combined > 0) {
            if (minSteps == -1 || combined < minSteps) {
                minSteps = combined;
                bestIndex = i;
            }
        }
    }

    cout << bestIndex << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (cin >> T) {
        while (T--) solve();
    }
    return 0;
}