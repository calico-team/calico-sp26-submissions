//#pragma GCC target ("avx2,tune=native")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define nl cout << '\n';
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define inpi(a) int a; cin >> a;
#define inpvi(a, n) vi a(n); for(auto &i : a) cin >> i;
#define inpvvi(a, x, y) vvi a(x, vi(y)); for(auto &i : a) for(auto &j : i) cin >> j;
#define YES do{cout << "YES";return;}while(0);
#define NO  do{cout << "NO ";return;}while(0);
#define rea(x)  do{cout << x;return;}while(0);

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vb = vector<bool>;
using vs = vector<string>;
using mii = map<int, int>;
using hashset = unordered_set<int, custom_hash>;
using hashmap = unordered_map <int, int, custom_hash>;

inline int iceil(int x, int y){return (x + y - 1) / y;}
inline bool amax(int &a, int b){bool r = a < b;a = max(a,b);return r;}
inline bool amin(int &a, int b){bool r = a > b;a = min(a,b);return r;}

constexpr int inf = numeric_limits<int>::max();



void solve()
{
    int k,n,m,p,q;
    cin >> k >> n >> m >> p >> q;
    vector<vb> ok(n, vb(m));
    int sx, sy;
    map<pair<int,int>, int> mp;
    for(int i = 0; i < k; ++i)
    {
        int x,y;
        cin >> x >> y;
        ok[x][y] = true;
        mp[{x,y}] = i;
        if(i == 0)
        {
            sx = x;
            sy = y;
        }
    }
    int cnt = 0;
    do
    {
        ++cnt;
        sx = (sx+q)%n;
        sy = (sy+p)%m;
    }while(!ok[sx][sy]);
    cout  << mp[{sx,sy}];
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    inpi(t);

    while(t--)
    {
        solve();
        cout << '\n';
    }
}

