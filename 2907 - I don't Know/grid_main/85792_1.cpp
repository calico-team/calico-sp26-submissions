#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll extended_gcd(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = extended_gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll modInverse(ll a, ll m) {
    ll x, y;
    ll g = extended_gcd(a, m, x, y);
    return (x % m + m) % m;
}

void solve() {
    int K;
    ll N, M, P, Q;
    if (!(cin >> K >> N >> M >> P >> Q)) return;

    vector<pair<ll, ll>> asteroids(K);
    for (int i = 0; i < K; i++) {
        cin >> asteroids[i].first >> asteroids[i].second;
    }

    ll X0 = asteroids[0].first;
    ll Y0 = asteroids[0].second;

    ll gx = gcd(Q, N);
    ll gy = gcd(P, M);

    ll Np = N / gx;
    ll Mp = M / gy;

    ll invQ = modInverse(Q / gx, Np);
    ll invP = modInverse(P / gy, Mp);

    ll g = gcd(Np, Mp);
    ll Mp_g = Mp / g;
    ll invNp = modInverse(Np / g, Mp_g);

    ll max_steps = Np * Mp_g;

    ll min_steps = -1;
    int best_idx = -1;

    for (int i = 0; i < K; i++) {
        ll Xi = asteroids[i].first;
        ll Yi = asteroids[i].second;

        ll dx = (Xi - X0) % N;
        if (dx < 0) dx += N;
        ll dy = (Yi - Y0) % M;
        if (dy < 0) dy += M;

        if (dx % gx != 0 || dy % gy != 0) continue;

        ll steps_x = ((dx / gx) * invQ) % Np;
        ll steps_y = ((dy / gy) * invP) % Mp;

        if ((steps_x - steps_y) % g != 0) continue;

        ll diff = (steps_y - steps_x) / g;
        diff %= Mp_g;
        if (diff < 0) diff += Mp_g;
        
        ll k = (diff * invNp) % Mp_g;
        ll total_steps = steps_x + k * Np;

        if (total_steps == 0) total_steps = max_steps;

        if (best_idx == -1 || total_steps < min_steps) {
            min_steps = total_steps;
            best_idx = i;
        }
    }
    cout << best_idx << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}