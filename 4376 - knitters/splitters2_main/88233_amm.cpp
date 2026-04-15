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
    ll p, x, y, q, r;
    cin >> p >> x >> y;
    ll p2 = (x >= 40 ? (ll)1e18 : (1LL << x)),p3 = 1;
    for (int i = 0; i < y; i++) {
        if (p3 > (ll)1e18 / 3) {
            p3 = (ll)1e18;
            break;
        }
        p3 *= 3;
    }
    if(p2 < (ll)1e18 && p3 < (ll)1e18 && p == p2*p3)
    {
        cout << "1 1\n>\n";
        return;
    }
    if(x >= 40)
    {
        q = 0;
        r = p;
    }
    else
    {
        ll a2 = 1LL << x;
        q = p / a2;
        r = p % a2;
    }
    vector<ll> d3(y, 0);
    ll temp = q;
    for(ll i = y - 1; i >= 0; i--)
    {
        d3[i] = temp % 3;
        temp /= 3;
    }
    const ll w = 9;
    ll k = x + y;
    ll hang = 2 * k + 3;
    vector<string> a(hang, string(w, '.'));
    a[0][0] = '>';
    a[0][1] = 'v';
    a[1][1] = '>';
    a[1][2] = 'v';
    ll row = 2;
    for(ll i = 0; i < y; i++)
    {
        ll d = d3[i];
        a[row][2] = 'S';
        a[row + 1][2] = 'v';
        if(d >= 1)
        {
            a[row][1] = '<';
            a[row][0] = '<';
        }
        else a[row][1] = 'X';
        for(ll j = 3; j < w - 1; j++) a[row][j] = '>';
        a[row][w - 1] = (d == 2) ? '>' : 'X';
        row += 2;
    }
    for(ll i = 0; i < x; i++)
    {
        ll bit = (r >> (x - 1 - i)) & 1;
        a[row][2] = 'S';
        a[row + 1][2] = 'v';
        for(ll j = 3; j < w - 1; j++) a[row][j] = '>';
        a[row][w - 1] = (bit == 1) ? '>' : 'X';
        row += 2;
    }
    a[row][2] = '>';
    for(ll i = 3; i < w - 1; i++) a[row][i] = '>';
    a[row][w - 1] = 'X';
    a.resize(row + 1);
    cout << row + 1 << " " << w << '\n';
    for(const string& s : a) cout << s << '\n';
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
