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


/*
 * Find an array B of N integers representing the filled-in second row,
 * chosen to minimize the sum of absolute differences of adjacent
 * numbers on the grid.
 * 
 * N: the number of columns in the 2 x N grid
 * A: vector of N integers giving the first row of the grid
 */
vector<int> solve(int N, vector<int>& A) {
    if(N<3){
        return A;
    }
    int best=INF;
    vi ans(N);
    each(a,A){
        each(b,A){
            each(c,A){
                int top=abs(A[0]-A[1])+abs(A[1]-A[2]);
                int bottom=abs(a-b)+abs(b-c);
                int betwennm=+abs(A[2]-c)+abs(A[1]-b)+abs(A[0]-a);
                if(top+bottom+betwennm<best){
                    best=top+bottom+betwennm;
                    ans={a,b,c};
                }
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        vector<int> result = solve(N, A);
        for (int i = 0; i < N; i++) {
            if (i > 0) cout << ' ';
            cout << result[i];
        }
        cout << '\n';
    }
    return 0;
}
