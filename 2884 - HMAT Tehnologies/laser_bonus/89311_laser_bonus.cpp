#include <algorithm>
#include <climits>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

using ll = long long;

static ll modNorm(ll a, ll m)
{
    a %= m;
    if (a < 0)
        a += m;
    return a;
}

static ll extGcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll g = extGcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

static ll invMod(ll a, ll m)
{
    ll x, y;
    ll g = extGcd(a, m, x, y);
    if (g != 1)
        return -1;
    return modNorm(x, m);
}

static bool solveLinearCongruence(ll coef, ll mod, ll rhs, ll &rem, ll &period)
{
    ll g = gcd(coef, mod);
    if (rhs % g != 0)
        return false;

    ll c = coef / g;
    ll m = mod / g;
    ll r = rhs / g;

    if (m == 1)
    {
        rem = 0;
        period = 1;
        return true;
    }

    ll inv = invMod(modNorm(c, m), m);
    rem = (modNorm(r, m) * inv) % m;
    period = m;
    return true;
}

static bool crt(ll a, ll n, ll b, ll m, ll &rem, ll &period)
{
    ll g = gcd(n, m);
    ll diff = b - a;
    if (diff % g != 0)
        return false;

    ll n2 = n / g;
    ll m2 = m / g;

    ll inv = 0;
    if (m2 > 1)
    {
        inv = invMod(modNorm(n2, m2), m2);
    }

    ll k = 0;
    if (m2 > 1)
    {
        k = (modNorm(diff / g, m2) * inv) % m2;
    }

    ll l = n * m2;
    ll r = a + n * k;
    r = modNorm(r, l);

    rem = r;
    period = l;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int K;
        ll N, M, P, Q;
        cin >> K >> N >> M >> P >> Q;

        vector<ll> X((size_t)K), Y((size_t)K);
        for (int i = 0; i < K; i++)
        {
            cin >> X[(size_t)i] >> Y[(size_t)i];
        }

        ll x0 = X[0], y0 = Y[0];

        ll bestT = LLONG_MAX;
        int bestIdx = 0;

        for (int i = 0; i < K; i++)
        {
            ll dx = modNorm(X[(size_t)i] - x0, N);
            ll dy = modNorm(Y[(size_t)i] - y0, M);

            ll a, n;
            if (!solveLinearCongruence(Q, N, dx, a, n))
                continue;

            ll b, m;
            if (!solveLinearCongruence(P, M, dy, b, m))
                continue;

            ll r, l;
            if (!crt(a, n, b, m, r, l))
                continue;

            ll t = (r == 0 ? l : r);
            if (t < bestT || (t == bestT && i < bestIdx))
            {
                bestT = t;
                bestIdx = i;
            }
        }

        cout << bestIdx << '\n';
    }

    return 0;
}
