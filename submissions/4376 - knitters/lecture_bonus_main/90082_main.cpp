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

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<string> a(n);
    vector<Pair> ghe;
    for(ll i = 0; i < n; i++)
    {
        cin >> a[i];
        for(ll j = 0; j < m; j++)
        {
            if(a[i][j] == '-') ghe.pb({i, j});
        }
    }
    ll s = n + m - 1, mov = m - 1;
    vector<vector<ll>> cnt(s, vector<ll>(s, 0));
    for(auto [r, c] : ghe)
    {
        ll u = r + c;
        ll v = r - c + mov;
        cnt[u][v]++;
    }
    vector<vector<ll>> pref(s + 1, vector<ll>(s + 1, 0));
    for(ll i = 1; i <= s; i++)
    {
        for(ll j = 1; j <= s; j++) pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + cnt[i - 1][j - 1];
    }
    auto ok = [&](ll x)
    {
        for(ll u1 = 0; u1 + x < s; u1++)
        {
            ll u2 = u1 + x;
            for(ll v1 = 0; v1 + x < s; v1++)
            {
                ll v2 = v1 + x;
                ll sum = pref[u2 + 1][v2 + 1] - pref[u1][v2 + 1] - pref[u2 + 1][v1] + pref[u1][v1];
                if(sum >= k) return 1;
            }
        }
        return 0;
    };
    ll l = 0, r = s;
    while(l < r)
    {
        ll mid = (l + r) >> 1;
        if(ok(mid)) r = mid;
        else l = mid + 1;
    }
    ll x = l, fu = -1, fv = -1;
    for(ll u1 = 0; u1 + x < s && fu == -1; u1++)
    {
        ll u2 = u1 + x;
        for(ll v1 = 0; v1 + x < s; v1++)
        {
            ll v2 = v1 + x;
            ll sum = pref[u2 + 1][v2 + 1] - pref[u1][v2 + 1] - pref[u2 + 1][v1] + pref[u1][v1];
            if(sum >= k)
            {
                fu = u1;
                fv = v1;
                break;
            }
        }
    }
    vector<Pair> ans;
    for(auto [r, c] : ghe)
    {
        ll u = r + c;
        ll v = r - c + mov;
        if(u >= fu && u <= fu + x && v >= fv && v <= fv + x)
        {
            ans.pb({r, c});
            if((ll)ans.size() == k) break;
        }
    }
    for(auto [r, c] : ans) cout << r << " " << c << '\n';
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
