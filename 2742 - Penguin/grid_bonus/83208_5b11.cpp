#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
ll dx[] = {-1, 0, 1, 0};
ll dy[] = {0, -1, 0, 1};
char dir[] = {'U', 'L', 'D', 'R'};
ll dx8[] = {1, -1, 0, 0, 1, -1, 1, -1};
ll dy8[] = {1, -1, 1, -1, 0, 0, -1, 1};
const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define ff first
#define ss second
#define pb push_back
#define pii pair<ll, ll>
#define pbb pair<bool, bool>
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define REP(i, a, b) for (ll i = a; i >= b; i--)
#define FORR(i, a, b, x) for (ll i = a; i < b; i += x)
#define pci pair<char, ll>
#define pic pair<ll, char>
#define psi pair<string, ll>
#define pis pair<ll, string>
#define pbl pair<bool, ll>
#define vd vector<double>
#define vvd vector<vd>
#define plb pair<ll, bool>
#define ppiii pair<pii, ll>
#define ppiipii pair<pii, pii>
#define vs vector<string>
#define vvs vector<vs>
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define vpbb vector<pbb>
#define vvpbb vector<vpbb>
#define qppiii queue<ppiii>
#define qppiipii queue<ppiipii>
#define qi queue<ll>
#define qpii queue<pii>
#define vppiii vector<ppiii>
#define vppiipii vector<ppiipii>
#define vc vector<char>
#define vvc vector<vc>
#define numbits(n) __builtin_popcount(n)
#define pqi priority_queue<ll>
#define rpqi priority_queue<ll, vi, greater<ll>>
#define srt(v) sort(v.begin(), v.end())
#define rsrt(v) sort(v.rbegin(), v.rend())
#define rev(v) reverse(v.begin(), v.end())
#define all(v) (v).begin(), (v).end()
#define biadj(adj, x, y) adj[x].pb(y); adj[y].pb(x); /*is this not genius? :D*/
#define srtt(v, comp) sort(v.begin(), v.end(), comp)
#define print(n) cout << n << endl; return 0;
#define szof(v) (ll)v.size()
#define fbo find_by_order
#define ook order_of_key
#define get1(n) ll n; cin >> n;
#define get2(n, m) ll n, m; cin >> n >> m;
#define get3(n, m, k) ll n, m, k; cin >> n >> m >> k;
#define get4(a, b, c, d) ll a, b, c, d; cin >> a >> b >> c >> d;
#define get5(a, b, c, d, e) ll a, b, c, d, e; cin >> a >> b >> c >> d >> e;
#define get6(a, b, c, d, e, f) ll a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
#define getn(n, v) vi v(n); FOR(i, 0, n) cin >> v[i];
#define printv(v) for (ll i = 0; i < v.size(); ++i) cout << v[i] << (i == v.size() - 1 ? "\n" : " ");
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
void setio(string name = "") {
 	fastio;
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

//im keeping this...
// ll random(const ordered_set<ll>& os) {
//     vector<ll> v(os.begin(), os.end());
//     random_device rd;
//     mt19937 rng(rd()); 
//     uniform_int_distribution<ll> uni(0, v.size() - 1);
//     ll idx = uni(rng);
//     return v[idx];
// }
//for fun yk

const ll mx = 2e5 + 10;

ll fastpow(ll a, ll b, ll mod) {
    //a ^ b % mod
    ll res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll fib(ll n) {
    vi dp(n + 1);
    dp[0] = dp[1] = 1;
    FOR(i, 2, n + 1) dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}

ll fact(ll n) {
    vi dp(n + 1);
    dp[1] = 1;
    FOR(i, 2, n + 1) dp[i] = i * dp[i - 1];
    return dp[n];
}

ll comb(ll n, ll k) {
    return (fact(n) / (fact(k) * fact(n - k)));
}

bool isprime(ll x) {
    if (x < 2) return 0;
    if (x < 4) return 1;
    if (x % 2 == 0 || x % 3 == 0) return 0;
    for (ll i = 5; i * i <= x; i += 6) {
        if (x % i == 0 || x % (i + 2) == 0) return 0;
    }
    return 1;
}

void compress(vi &v) {
    srt(v);
    v.erase(unique(all(v)), v.end());
}

ll a[mx];
void sieve() {
    iota(a, a + mx, 0);
    for (ll i = 2; i * i < mx; i++) if (a[i] == i) for (ll j = i * i; j < mx; j += i) if (a[j] == j) a[j] = i;
}

vi factors(ll n) {
    vi factors;
    while (n > 1) {
        factors.pb(a[n]);
        n /= a[n];
    }
    return factors;
}

struct SegTree {
    ll n;
    vi tree;
    void init(ll x) {
        n = x;
        tree.assign(4 * n + 1, 0LL);
    }
    void update(ll node, ll start, ll end, ll idx, ll val) {
        //ie change idx to new val
        if (start == end) { tree[node] = val; return; }
        ll mid = (start + end) / 2;
        if (idx <= mid) update(2 * node, start, mid, idx, val);
        else update(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1]; //CHANGE FOR DIFFERENT QUERIES
    }
    ll query(ll node, ll start, ll end, ll l, ll r) {
        //ie find sum of range l->r
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        ll mid = (start + end) / 2;
        return query(2 * node, start, mid, l, r) + query(2 * node + 1, mid + 1, end, l, r);
    }
};

ll n, m;
ll idx(ll i, ll j) {
    return i * m + j;
}


struct DSU {
    vi p, s;
    ll num;
    DSU(ll n) {
        p = vi(n + 1, -1);
        s = vi(n + 1, 1);
        num = 0;
    }
    ll find(ll x) {
        return (p[x] < 0 ? x : p[x] = find(p[x]));
    }
    bool same(ll x, ll y) {
        return (find(x) == find(y));
    }
    ll sz(ll x) {
        return s[find(x)];
    }
    bool unite(ll x, ll y) {
        x = find(x), y = find(y);
        if (x == y) return 0;
        if (s[x] < s[y]) swap(x, y);
        s[x] += s[y];
        p[y] = x;
        --num;
        return 1;
    }
};

struct Edge {
    ll a, b, c;
};

bool mstcomp(Edge x, Edge y) {
    return x.c < y.c;
}

//KRUSKAL
ll kruskal(vector<Edge>& edges, ll n) {
    srtt(edges, mstcomp);
    DSU dsu(n);
    ll ans = 0;
    ll cnt = 0;
    for (auto [n1, n2, w] : edges) {
        if (dsu.unite(n1, n2)) {
            ans += w; 
            ++cnt;
        }
        if (cnt == n - 1) break;
    }
    return ans;
}

/*
qi q;
vb visited(n + 1, 0);
FOR(i, 1, n + 1) {
    if (visited[i]) continue;
    q.push(i);
    visited[i] = 1;
    while (!q.empty()) {
        auto curr = q.front; q.pop();
        for (auto u : adj[curr]) {
            if (visited[u]) continue;
            visited[u] = 1;
            q.push(u);
        }
    }
}
*/

struct Point {
    ld x, y;
};

ld dist(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void solve() {
    int n;
    cin >> n;
    vi v(n);
    FOR(i, 0, n) cin >> v[i];
    vi ans(n);
    FOR(i, 0, n) ans[i] = v[i];
    FOR(trash, 0, 500) {
        FOR(i, 0, n) {
            vi ne;
            ne.pb(v[i]);
            if (i > 0) ne.pb(ans[i - 1]);
            if (i < n - 1) ne.pb(ans[i + 1]);
            srt(ne);
            if (szof(ne) == 3) ans[i] = ne[1];
            else ans[i] = (ne[0] + ne[1]) / 2;
        }
    }
    FOR(i, 0, ans.size()) cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
    return;
}


signed main() {
    setio("");
    ll t = 1;
    cin >> t;
    while (t--) solve();
}
// Bessie says hi vvv

/*
\|/          (___)    
     `\------(o o) \|/        \|/
       ||    (___)        \|/
       ||w--||     \|/          \|/
   \|/        \|/        \|/
*/
//yay thanks Chongtian


