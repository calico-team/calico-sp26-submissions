#include <algorithm>
#include <bits/stdc++.h>
 
using namespace std;
using namespace std::chrono;


ostream& operator<<(ostream& o, const __int128& x) {
    if (x == numeric_limits<__int128>::min()) return o << "-170141183460469231731687303715884105728";
    if (x < 0) return o << "-" << -x;
    if (x < 10) return o << (char)(x + '0');
    return o << x / 10 << (char)(x % 10 + '0');
}
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(__int128 x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...) 
#endif

int setbit(int x) {return __builtin_popcount(x);}
int setbit(long long x) {return __builtin_popcountll(x);}
int highbit(int x) {return (x==0?-1:31-__builtin_clz(x));}
int highbit(long long x) {return (x==0?-1:63-__builtin_clzll(x));}
int lowbit(int x) {return (x==0?-1:__builtin_ctz(x));}
int lowbit(long long x) {return (x==0?-1:__builtin_ctzll(x));}
#define ll long long
// #define int ll
#define inf ((int)1e9 + 5)
#define inf_long_long (9223372036854775807LL/4)
#define endl "\n"
#define mod 1000000007
#define fastinput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define umap unordered_map
#define pii pair<int,int>
#define ppiii pair<pii, int>
#define pipii pair<int, pii>
#define sz(x) ((int) x.size())
#define forn(i,a,b) for(int i=a;i<=b;i++)
#define for0(i,a,b) for(int i=a;i>=b;i--)
#define all(x) x.begin(), x.end()
typedef tuple<int,int,int> tiii;
typedef __int128 i128;
template<typename T,typename U>
T ceil(T x, U y) {return (x>0?(x+y-1)/y:x/y);}
vector<int> factorials;
vector<int> invf;
int bpm(int a, int b) {if (b==0) {return 1;} int ret = bpm(a, b/2); ret = (1LL * ret * ret) % mod; if (b%2==1) {ret = (1LL * ret * a) % mod;} return ret;}
int gcd(int a, int b) {if (a==0) {return b;} if (b==0) {return a;}return gcd(b%a, a);}
int lcm(int a, int b) {return a/gcd(a,b)*b;}
int inv(int a) {return bpm(a, mod-2);}
void calcfacmod(int n) {factorials.resize(n+1);factorials[0] = 1;for (int i = 1; i <= n; i++) {factorials[i] = factorials[i-1]*i;factorials[i]%=mod;}}
mt19937_64 rngg(time(0));
ll RNG() {return rngg()%inf_long_long;} // IF CHANGE INT -> THEN CHANGE
void calcfac(int n) {calcfacmod(n);}

template<typename T>
void modpos(T &a) {T amt = (-a)/mod;amt++; amt = max(T(0), amt); a += amt*mod; a%=mod;}

int chs(int a, int b) {if (a<b || b < 0) {return 0;}if (b==a || b==0) {return 1;}return (((factorials[a]*invf[b])%mod)*invf[a-b])%mod;}
void calcinvfac(int n) {invf.resize(n);invf[n - 1] = inv(factorials[n - 1]);for (int i = n - 1; i > 0; i--) {invf[i - 1] = (invf[i] * i) % mod;}}
int ceil(int a, int b) {return (a / b) + (!!(a % b));}
// int paths(int a, int b) {return choose(a+b, a);}
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using namespace std;
// template<typename T> 
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // remove #define int ll before use

const int BDV = (int)530;
int vis[2 * BDV][2 * BDV];

int ky = 0;

// struct qy {
//     int x, y, t, d;
// };

vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {1, -1, 0, 0};

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a > c) {
        swap(a, c);
    }
    if (b > d) {
        swap(b, d);
    }
    a += BDV;
    b += BDV;
    c += BDV;
    d += BDV;
    priority_queue<pair<pii, pii>, vector<pair<pii, pii> >, greater<pair<pii, pii> > > pq;
    pq.push({{0, 1}, {c, d}});
    pq.push({{0, 0}, {a, b}});
    ky++;
    int ans = 0;
    int tt = 1;
    while (sz(pq)) {
        c = pq.top().first.first;
        int t = pq.top().first.second;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        tt -= t;
        if (vis[x][y] <= ky) {
            // if (t) {
            // //     debug(x, y, c, t, tt);
            //     assert(!(!x || !y || x == 2 * BDV - 1 || y == 2 * BDV - 1));
            // }
            vis[x][y] = ky + 1;
            ans += t;
            // vector<int> nxv = {x, x, x - 1, x + 1};
            // vector<int> nyv = {y - 1, y + 1, y, y};
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < 2 * BDV && ny < 2 * BDV && vis[nx][ny] <= ky) {
                    tt += t;
                    // pair<pii, pii> ad = {{c + 2 + 5 * t, t}, {nx, ny}};
                    pq.push({{c + 2 + 5 * t, t}, {nx, ny}});
                }
            }
        }
        if (!tt) {
            break;
        }
    }
    cout << ans << endl;
}

signed main() {
    fastinput;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}