#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll extended_gcd(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = extended_gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

ll modInverse(ll a, ll m) {
    ll x, y;
    ll g = extended_gcd(a, m, x, y);
    return (x % m + m) % m;
}

void solve() {
    int K;
    ll N, M, P, Q;
    cin >> K >> N >> M >> P >> Q;

    vector<pair<ll, ll>> asteroids(K);
    for (int i = 0; i < K; i++) {
        cin >> asteroids[i].first >> asteroids[i].second;
    }

    ll startX = asteroids[0].first;
    ll startY = asteroids[0].second;

    ll invQ = modInverse(Q, N);
    ll invP = modInverse(P, M);

    ll firstAsteroidIndex = -1;
    ll minSteps = -1;

    for (int i = 0; i < K; i++) {
        ll targetX = asteroids[i].first;
        ll targetY = asteroids[i].second;

        ll dx = (targetX - startX % N + N) % N;
        ll dy = (targetY - startY % M + M) % M;

        ll stepX = (dx * invQ) % N;
        ll stepY = (dy * invP) % M;

        ll x, y;
        ll g = extended_gcd(N, M, x, y);
        
        if ((stepY - stepX) % g != 0) continue;

        ll mod = (N * M) / g;
        ll combinedSteps = (stepX + N * ((stepY - stepX) / g * x % (M / g))) % mod;
        if (combinedSteps < 0) combinedSteps += mod;

        if (combinedSteps == 0 && i == 0) {
            combinedSteps = mod;
        }

        if (combinedSteps > 0) {
            if (minSteps == -1 || combinedSteps < minSteps) {
                minSteps = combinedSteps;
                firstAsteroidIndex = i;
            }
        }
    }

    cout << firstAsteroidIndex << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}