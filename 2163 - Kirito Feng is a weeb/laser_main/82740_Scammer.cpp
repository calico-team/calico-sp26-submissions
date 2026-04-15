#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;
ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll extGCD(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = extGCD(b,a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

ll modInv(ll a,ll m) {
    if (m == 1) return 0;
    ll x, y;
    extGCD(a, m, x, y);
    return (x % m + m) % m;
}

ll solve1(ll Q, ll dX, ll N, ll &tx, ll &mx) {
    ll g = gcd(Q, N);
    if (dX % g != 0) return -1;
    mx = N / g;
    ll Qprime = Q / g;
    ll dXprime = dX / g;
    ll invQ = modInv(Qprime, mx);
    tx = (dXprime % mx * invQ % mx) % mx;
    if (tx < 0) tx += mx;
    return 0;
}

ll solve2(ll tx, ll mx, ll ty, ll my) {
    ll g = gcd(mx, my);
    ll diff = ty - tx;
    if (diff % g != 0) return -1;
    ll nprime = my / g;
    ll diffp = diff / g;
    diffp = (diffp % nprime + nprime) % nprime;
    ll mprime = mx / g;
    ll invM = modInv(mprime, nprime);
    ll k = (diffp * invM) % nprime;
    ll t = tx + k * mx;
    ll L = (mx / g) * my;
    if (t == 0) t += L;
    return t;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        ll K, N, M, P, Q;
        cin >> K >> N >> M >> P >> Q;

        vector<pair<ll, ll>> a(K);
        for (int i = 0; i < K; ++i) {
            cin >> a[i].first >> a[i].second;
        }

        ll X0 = a[0].first;
        ll Y0 = a[0].second;

        ll mint = -1;
        int bestidx = -1;

        for (int i = 0; i < K; ++i) {
            ll dX = (a[i].first - X0) % N;
            if (dX < 0) dX += N;
            ll dY = (a[i].second - Y0) % M;
            if (dY < 0) dY += M;

            ll tx, mx, ty, my;
            if (solve1(Q, dX, N, tx, mx) == -1) continue;
            if (solve1(P, dY, M, ty, my) == -1) continue;

            ll t = solve2(tx, mx,ty, my);
            if (t != -1) {
                if (mint == -1 || t < mint) {
                    mint = t;
                    bestidx = i;
                }
            }
        }

        cout << bestidx<< "\n";
    }
    return 0;
}