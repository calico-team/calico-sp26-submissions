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
    ll p, x, y;
    cin >> p >> x >> y;
    __int128 d = 1;
    for(ll i = 0; i < x; i++) d *= 2;
    for(ll i = 0; i < y; i++) d *= 3;
    bool allcol = (d == p);
    ll q = 0, r = p;
    if(!allcol && x < 40)
    {
        ll a2 = 1LL << x;
        q = p / a2;
        r = p % a2;
    }
    vector<ll> d3(y, 0);
    if(allcol)
    {
        for(ll i = 0; i < y; i++) d3[i] = 2;
    }
    else
    {
        ll temp = q;
        for(ll i = y - 1; i >= 0; i--)
        {
            d3[i] = temp % 3;
            temp /= 3;
        }
    }
    vector<ll> bits2(x, 0);
    if(allcol)
    {
        for(ll i = 0; i < x; i++) bits2[i] = 1;
    }
    else
    {
        for(ll i = 0; i < x; i++)
        {
            ll mov = x - 1 - i;
            if(mov < 64) bits2[i] = (r >> mov) & 1;
            else bits2[i] = 0;
        }
    }
//    for(ll i : bits2) cout << i << " ";
    const ll w = 5;
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
        a[row][3] = '>';
        for(ll j = 4; j < w; j++) a[row][j] = '>';
        a[row][w - 1] = (d == 2) ? '>' : 'X';
        row += 2;
    }
    for(ll i = 0; i < x; i++)
    {
        ll bit = bits2[i];
        a[row][2] = 'S';
        a[row + 1][2] = 'v';
        a[row][3] = '>';
        for(ll j = 4; j < w; j++) a[row][j] = '>';
        a[row][w - 1] = (bit == 1) ? '>' : 'X';
        row += 2;
    }
    a[row][2] = '>';
    for(ll i = 3; i < w; i++) a[row][i] = '>';
    a[row][w - 1] = (allcol ? '>' : 'X');
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
