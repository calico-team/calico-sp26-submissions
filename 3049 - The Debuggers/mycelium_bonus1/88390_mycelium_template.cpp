#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <climits>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <array>

using namespace std;

using ll = long long;
using db = long double;
using str = string;
template<typename T, typename T1>
using P = pair<T, T1>;
using pll = P<ll, ll>;
using pii = P<int, int>;
template <typename T>
using V = vector<T>; 
using vi = V<int>;
using vb = V<bool>;
using vd = V<db>;
using vs = V<str>;
using vll = V<ll>;
using vvll = V<vll>;
using vvi = V<vi>;
using vpii = V<pii>;
using vpll = V<pll>;
using vvpii = V<vpii>;
using vvpll = V<vpll>;
template <typename T, size_t SZ>
using AR = array<T, SZ>;
template <typename T, typename Container = vector<T>, typename Compare = less<T>>
using pqu = priority_queue<T, Container, Compare>;
template <typename T>
using qu = queue<T>;
#define mp make_pair
#define f first
#define s second
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define sor(x) sort(all(x))
#define sz(x) int((x).size())
#define rz resize
#define ins insert
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()
#define FOR(i, a) for(int i = 0; i < a; i++)
#define ROF(i, a) for(int i = a; i >= 0; i--)
#define FORA(i, a, b) for(int i = a; i <= b; i++)
#define ROFA(i, a, b) for(int i = a; i >= b; i--)
#define each(a,x) for (auto& a: x)
#define lb lower_bound
#define ub upper_bound
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define nl cout << "\n"

template<typename T>
int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-begin(a)); } 
template<typename T>
int upb(V<T>& a, const T& b) { return int(ub(all(a),b)-begin(a)); }

template<typename T1, typename T2>
istream& operator>>(istream& is, pair<T1, T2>& p) { is >> p.f >> p.s; return is; }
template<typename T>
istream& operator>>(istream& is, V<T>& a) { each(x, a) is >> x; return is; }
template<typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {os << p.f << " " << p.s << "\n"; return os; }
template<typename T>
ostream& operator<<(ostream &os, const V<T>& a) { each(x, a) os << x << " "; os << '\n'; return os; }

template<typename T>
T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<typename T>
T lcm(T a, T b) { return a / gcd(a, b) * b; }
#define mid(a, b) ((a + b) / 2)

const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0}; 
const int dx8[8] = {0, 0, 1, 1, 1, -1, -1, -1}, dy8[8] = {1, -1, 0, 1, -1, 0, 1, -1}; 
const int INF = 1e9 + 7;
const ll INFLL = 1e18 + 7;

template<typename T>
V<T> dijkstra(int start, const V<V<pair<int, T>>> &adj, int p, T BIGNUM) {
    V<T> dist(p, BIGNUM);
    pqu<pair<T, int>, V<pair<T, int>>, greater<pair<T, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (d > dist[u]) continue;

        for(auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

template<typename T>
V<T> prefix(const V<T>& a) {
    V<T> p(sz(a) + 1, 0);
    FOR(i, sz(a)) p[i + 1] = p[i] + a[i];
    return p;
}

template<typename T>  
bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0;
}
template<typename T>  
bool ckmax(T& a, const T& b) { 
    return a < b ? a = b, 1 : 0;    
}

template<typename T>
struct DSU{
    int cc;  vector<T> parents;
    DSU(T N) : parents(N, -1) { cc = N; }
    T find(T x) { return parents[x] < 0 ? x : parents[x] = find(parents[x]); }
    bool unite(T x, T y) {
        x = find(x), y = find(y); if (x == y) return 0;
        cc--;
        if (parents[x] > parents[y]) swap(x, y); 
        parents[x] += parents[y];
        parents[y] = x;
        return 1;
    }
    bool connected(T x, T y) { return find(x) == find(y); }
    T size(T x) { return -parents[find(x)]; }
};


int solve(int X_G, int Y_G, int X_M, int Y_M) {
    //bondign mbox
    ll d=abs((ll)X_G - X_M) + abs((ll)Y_G - Y_M);
    ll r=4*d + 50;
    ll x=((ll)X_G + X_M) / 2;
    ll y=((ll)Y_G + Y_M) / 2;
    ll minX=x-r,maxX = x + r;
    ll minY=y- r, maxY = y + r;

    const int off = 2000, sz = 4000;
    vector<vector<int8_t>> imperalismmygoat(sz, vector<int8_t>(sz, -1));

    using Event = tuple<ll, int, int, int>;
    pqu<Event, V<Event>, greater<Event>> pq;

    pq.push({0, 0, X_G+off, Y_G+off});
    pq.push({0, 1, X_M+off, Y_M+off});
    int ans=0;

    while(!pq.empty()) {
        auto [t, gm, x, y] = pq.top(); pq.pop();

        //ignroe otuside nbxos 
        if(x<0 ||x>=sz||y<0|| y >=sz) continue;
        if(imperalismmygoat[x][y]!=-1) continue;

        imperalismmygoat[x][y]=gm;
        if(gm==1)ans++;

        FOR(k, 4) {
            int nx = x + dx[k], ny = y + dy[k];
            if(nx<0 ||nx>=sz||ny<0|| ny >=sz) continue;
            if(imperalismmygoat[nx][ny]!=-1) continue;
            if(gm==0){
                pq.push({t + 2, gm, nx, ny});
            }else{
                pq.push({t + 7, gm, nx, ny});
            }
        }
    }

    return ans;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int X_G, Y_G, X_M, Y_M;
        cin >> X_G >> Y_G >> X_M >> Y_M;
        cout << solve(X_G, Y_G, X_M, Y_M) << '\n';
    }
}