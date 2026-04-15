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

unordered_map<char, Pair> dir = {
    {'^', {-1, 0}},
    {'v', {1, 0}},
    {'<', {0, -1}},
    {'>', {0, 1}},
    {'~', {1, 0}}
};

struct frac{
    ll num, den;
    frac(ll n = 0, ll d = 1)
    {
        if(d < 0) n = -n, d = -d;
        ll g = __gcd(abs(n), d);
        num = n / g;
        den = d / g;
    }
    frac operator+(const frac& o) const
    {
        ll n = (ll)num * o.den + (ll)o.num * den;
        ll d = (ll)den * o.den;
        ll g = __gcd((ll)abs(n), (ll)d);
        return frac((ll)(n / g), (ll)(d / g));
    }
    frac operator*(const frac& o) const
    {
        ll n = (ll)num * o.num;
        ll d = (ll)den * o.den;
        ll g = __gcd((ll)abs(n), (ll)d);
        return frac((ll)(n / g), (ll)(d / g));
    }
};

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<string> a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    ll ncnt = n * m + 2;
    ll collect = n * m;
    ll destroy = n * m + 1;
    vector<vector<pair<ll, frac>>> adj(ncnt);
    for(ll r = 0; r < n; r++)
    {
        for(ll c = 0; c < m; c++)
        {
            char ch = a[r][c];
            ll u = r * m + c;
            if(ch == '.') continue;
            if(ch == 'X' || ch == 'x') adj[u].pb({destroy, frac(1, 1)});
            else if(dir.count(ch))
            {
                auto temp = dir[ch];
                auto dr = temp.fi;
                auto dc = temp.se;
                ll nr = r + dr, nc = c + dc, v;
                if(nr < 0 || nr >= n || nc < 0 || nc >= m) v = collect;
                else v = nr * m + nc;
                adj[u].pb({v, frac(1, 1)});
            }
            else if(ch == 'S' || ch == 's')
            {
                vector<ll> aim;
                vector<Pair> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
                for(auto temp : dirs)
                {
                    auto dr = temp.fi;
                    auto dc = temp.se;
                    ll nr = r + dr, nc = c + dc;
                    if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                    char nch = a[nr][nc];
                    if(nch == 'X' || nch == 'x') aim.pb(nr * m + nc);
                    else if(dir.count(nch))
                    {
                        auto temp = dir[nch];
                        auto cdr = temp.fi;
                        auto cdc = temp.se;
                        if(!(nr + cdr == r && nc + cdc == c)) aim.pb(nr * m + nc);
                    }
                }
                ll k = aim.size();
                if(k > 0)
                {
                    frac w(1, k);
                    for(ll v : aim) adj[u].pb({v, w});
                }
            }
        }
    }
    vector<vector<pair<ll, frac>>> rev(ncnt);
    for(ll u = 0; u < n * m; u++)
    {
        for(auto temp : adj[u])
        {
            auto v = temp.fi;
            auto w = temp.se;
            rev[v].pb({u, w});
        }
    }
    vector<frac> mem(ncnt, frac(-1, 1));
    ll st = 0;
    function<frac(ll)> solvef = [&](ll u) -> frac{
        if(mem[u].num != -1) return mem[u];
        if(u == st) return frac(1, 1);
        frac sum(0, 1);
        for(auto temp : rev[u])
        {
            auto prev = temp.fi;
            auto w = temp.se;
            sum = sum + solvef(prev) * w;
        }
        mem[u] = sum;
        return sum;
    };
    frac ans = solvef(collect);
    cout << ans.num << " " << ans.den << '\n';
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
