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
    ll n, m;
    cin >> n >> m;
    for(ll i = 0; i < n; i++)
    {
        for(ll j = 0; j < m; j++)
            {
            ll x = (i + 2 * j) % 5;
            cout << x;
            if(j + 1 < m) cout << " ";
        }
        cout << '\n';
    }
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
