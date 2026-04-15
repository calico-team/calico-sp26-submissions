// Problem 2: Nah I’d Win
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int ,int, int> ti;
typedef pair<pi, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pl;
typedef tuple<ll,ll,ll> tl;
typedef pair<ll,pl> pll;
typedef pair<string, int> psi;
typedef vector<int> vi;
typedef set<int> si;
typedef set<ll> sl;
typedef queue<int> qi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<pi> vii;
typedef vector<ti> vti;
typedef vector<pl> vll;
typedef vector<tl> vtl;
typedef vector<pii> viii;
typedef vector<bool> vb;
typedef priority_queue<int, vi> ipq;
typedef priority_queue<int, vi, greater<>> ripq;
#define endl '\n'
#define FILL(a, b) memset(a, b, sizeof(a))
#define ALL(x) x.begin(), x.end()
#define LOOP(n) for (int _ = 0; _ < n; _++)
#define PRIMLOOP(N) for (int i = 0; i < N; i++)
#define SECLOOP(M) for (int j = 0; j < M; j++)
#define RLOOP(n) for (int i = n; i >= 0; i--)
#define ILOOP(arr) for (int &i: arr)
#define CLOOP(s) for (char c: s)
#define pb push_back
#define FOUNDANS(res) {cout << res << endl; return 0;}
#define pq priority_queue
#define vc vector

constexpr int MM = 1e5+5;
constexpr int INF = 0x3F3F3F3F;
constexpr ll INFL = 0x3F3F3F3F3F3F3F3FLL;
constexpr int MOD = 1e9 + 7;

const string lose = "nah i'd lose\n";

void solve()
{
    int N, cpower, R, K; cin >> N >> cpower >> R >> K;
    vi E(N); PRIMLOOP(N) cin >> E[i];

    if (E[0] > cpower) {cout << lose; return;}

    int curses = 0;
    PRIMLOOP(N)
    {
        if (curses == K) {cpower += R; curses = 0;}
        cpower -= E[i];
        curses++;
        if (cpower < 0) {cout << lose; return;}
    }

    cout << "nah i'd win\n";
}

/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;
    LOOP(T)
    {
        solve();
    }

    return 0;
}
