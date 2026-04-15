// Problem 8: ucb wrote a problem abt grass and shrooms
#include <bits/stdc++.h>
using namespace std;
char alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

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

void solve(ll XG, ll YG, ll XM, ll YM)
{
    ll res = 1;

    ll dr[] = {1, -1, 0, 0};
    ll dc[] = {0, 0, -1, 1};

    queue<pl> Q; Q.emplace(XG,YG);
    set<pl> vis; vis.insert({XG,YG});
    while(!Q.empty())
    {
        const ll cr = Q.front().first, cc = Q.front().second; Q.pop();
        for (int i = 0; i < 4; i++)
        {
            ll nr = cr + dr[i], nc = cc + dc[i];
            if (vis.count({nr,nc})) continue;
            vis.insert({nr,nc});

            const ll dg = abs(nc - XG) + abs(nr - YG);
            const ll dm = abs(nc - XM) + abs(nr - YM);
            if (7 * dm < 2 * dg) {
                vis.insert({nr, nc});
                res++;
                Q.emplace(nr, nc);
            }
        }
    }

    cout << res << endl;
}

/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;
    ll XG,YG,XM,YM;
    LOOP(T)
    {
        cin >> XG >> YG >> XM >> YM;
        solve(XG, YG, XM, YM);
    }

    return 0;
}
