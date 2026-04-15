#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
ll modinv(ll a, ll m) {
    ll x, y;
    ll g = gcd(a, m, x, y);
    if (g != 1) return -1;
    return (x % m + m) % m;
}
void solve() {
    ll K, N, M, P, Q;
    cin >> K >> N >> M >> P >> Q;
    vector<pair<ll, ll>> ast(K);
    for (int i = 0; i < K; i++) cin >> ast[i].first >> ast[i].second;

    ll X0 = ast[0].first;
    ll Y0 = ast[0].second;

    ll minst = -1;
    int bix = -1;

    for (int i = 0; i < K; ++i) {
        ll tary = (ast[i].second - Y0 % M + M) % M;
        ll tarx = (ast[i].first - X0 % N + N) % N;
        ll x, y;
        ll inv1, inv2;
        ll gY = gcd(P, M, inv1, inv2);
        ll gX = gcd(Q, N, inv1, inv2);
        if (tarx % gX != 0) continue;
        ll a = (tarx / gX * (inv1 % (N/gX) + (N/gX))) % (N/gX);
        ll modB = M / gY;
        ll b = (tary / gY * (inv1 % (M/gY) + (M/gY))) % (M/gY);
        ll modA = N / gX;
        if (tary % gY != 0) continue;
        ll g = gcd(modA, modB, x, y);
        ll lcm = (modA / g) * modB;
        if ((b - a) % g != 0) continue;
        ll s = (a + x * (b - a) / g % (modB / g) * modA) % lcm;
        if (s < 0) s += lcm;
        if (s == 0 && i == 0) s = lcm;
        if (bix == -1 || s < minst) {
            bix = i;
            minst = s;
        }
    }
    cout << bix << endl;
}
int main() {
    int T; cin >> T;
    while (T--) solve();
}
