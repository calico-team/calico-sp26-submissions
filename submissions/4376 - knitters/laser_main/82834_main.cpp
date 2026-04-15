#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define se second
#define fi first
#define pb push_back
#define pf push_front
#define ld long double
#define INF 1e18
#define lcm(x, y) x / __gcd(x, y) * y
#define Pair pair<ll, ll>
#define pii pair<int, int>
#define Pq priority_queue<ll>
#define Pqr priority_queue<ll, vector<ll>, greater<ll >>
#define clockst clock_t tStart = clock()
#define clockfin printf("Time taken: %.2fs\n",(double)(clock() - tStart)/CLOCKS_PER_SEC)
#define all(x) x.begin(), x.end()
#define eb emplace_back
#define mp make_pair
#define mems(a, x) memset((a),(x), sizeof(a))
//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,popcnt,lzcnt,bmi,bmi2,fma")
typedef unsigned long long ull;
void init() { freopen("cf.INP", "r", stdin); freopen("cf.OUT", "w", stdout); }
ll xc[5] = { -1, 1, 0, 0 }, yc[5] = { 0, 0, 1, -1 };
ll xc8[8] = { -1, 1, 0, 0, -1, 1, -1, 1 };
ll yc8[8] = { 0, 0, 1, -1, -1, 1, 1, -1 };
const long double pi = acosl(-1.0L);

inline ll read()
{
    ll x = 0;
    char ch = getchar();;
    bool str = 1;
    while(ch < '0' || ch > '9')
    {
        if(ch == '-') str = 0; ch = getchar();;
    }
    while(ch >= '0' && ch <= '9')
    {
        x =((x << 3) +(x << 1)) + ch - '0';
        ch = getchar();;
    }
    return str ? x : x;
}

ll modinv(ll a, ll m)
{
    ll mx = m, t, q;
    ll xx = 0, xy = 1;
    if (m == 1) return 0;
    while (a > 1)
    {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = xx;
        xx = xy - q * xx;
        xy = t;
    }
    if (xy < 0) xy += mx;
    return xy;
}

void solve()
{
    ll k, n, m, p, q;
    cin >> k >> n >> m >> p >> q;
    vector<ll> x(k), y(k);
    for(ll i = 0; i < k; i++) cin >> x[i] >> y[i];
    ll xx = x[0], yx = y[0];
    ll bestt = LLONG_MAX, ans = -1;
    for(ll i = 0; i < k; i++)
    {
        ll dx = (x[i] - xx) % n;
        if (dx < 0) dx += n;
        ll dy = (y[i] - yx) % m;
        if (dy < 0) dy += m;
        ll gn = __gcd(q, n);
        if (dx % gn != 0) continue;
        ll qp = q / gn;
        ll np = n / gn;
        ll dxp = dx / gn;
        ll invq = modinv(qp, np);
        ll t0 = (dxp * invq) % np;
        ll gm = __gcd(p, m);
        if (dy % gm != 0) continue;
        ll pp = p / gm;
        ll mp = m / gm;
        ll dyp = dy / gm;
        ll invP = modinv(pp, mp);
        ll t1 = (dyp * invP) % mp;
        ll g = __gcd(np, mp);
        if ((t0 % g) != (t1 % g)) continue;
        ll npp = np / g;
        ll mpp = mp / g;
        ll rhs = (t1 - t0) / g;
        ll invnpp = modinv(npp, mpp);
        ll rmod = (rhs % mpp + mpp) % mpp;
        ll kx = (rmod * invnpp) % mpp;
        ll l = np * mpp;
        ll tans = (t0 + np * kx) % l;
        ll t = (tans == 0) ? l : tans;
        if (t < bestt || (t == bestt && i < ans))
        {
            bestt = t;
            ans = i;
        }
    }
    cout << ans << '\n';
}

bool multest = 1;

int main()
{
    fast;
    ll t = 1;
    if(multest) cin >> t;
    while(t--) solve();
    return 0;
}
