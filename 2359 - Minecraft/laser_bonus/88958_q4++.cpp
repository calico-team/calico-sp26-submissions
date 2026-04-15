#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}
ll solveLinearCongruence(ll a, ll b, ll m) {
    ll x, y;
    ll d = exgcd(a, m, x, y);
    if (b % d != 0) return -1;
    ll mod = m / d;
    return (x * (b / d) % mod + mod) % mod;
}
ll mergeEquations(ll a1, ll m1, ll a2, ll m2) {
    if (a1 == -1 || a2 == -1) return -1;
    ll x, y;
    ll d = exgcd(m1, m2, x, y);
    if ((a2 - a1) % d != 0) return -1;
    
    ll mod = (m1 / d) * m2; 
    ll k = solveLinearCongruence(m1, (a2 - a1 + m2) % m2, m2);
    return (a1 + k * m1) % mod;
}
void solve() {
    int K;
    ll N, M, P, Q;
    if (!(cin >> K >> N >> M >> P >> Q)) return;
    vector<pair<ll, ll>> asteroids(K);
    for (int i = 0; i < K; ++i) {
        cin >> asteroids[i].first >> asteroids[i].second;
    }
    ll startX = asteroids[0].first;
    ll startY = asteroids[0].second;
    ll minSteps = -1;
    int targetIdx = -1;
    for (int i = 0; i < K; ++i) {
        ll dX = (asteroids[i].first - startX + M) % M;
        ll dY = (asteroids[i].second - startY + N) % N;
        ll t1 = solveLinearCongruence(Q, dX, M);
        ll t2 = solveLinearCongruence(P, dY, N);
        ll t = mergeEquations(t1, M, t2, N);
        if (t == 0) {
            ll x_dummy, y_dummy;
            ll common_mod = (M / exgcd(M, N, x_dummy, y_dummy)) * N;
            t = common_mod; 
        }

        if (t != -1) {
            if (minSteps == -1 || t < minSteps) {
                minSteps = t;
                targetIdx = i;
            }
        }
    }
    cout << targetIdx << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}