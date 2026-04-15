#include <bits/stdc++.h>
 
using namespace std;
 
#define forsn(i, s, n) for (int i = int(s); i < int(n); i++)
#define forn(i, n) forsn(i, 0, n)
#define dforsn(i, s, n) for (int i = int(n) - 1; i >= int(s); i--)
#define dforn(i, n) dforsn(i, 0, n)
 
using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vb = vector<bool>;
using pll = pair<ll, ll>;
using bint = __int128;
 
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
 
#define pb push_back
#define eb emplace_back
 
#define fst first
#define snd second

void dfs(int u, vector<vi> &adj, vi &vis, vi &deg) {
    if (vis[u]) return;
    vis[u] = 1;
    for (int v : adj[u]) {
        deg[v]++;
        dfs(v, adj, vis, deg);
    }
}

pll &operator+=(pll &a, pll b) {
    b.fst *= a.snd;
    a.fst *= b.snd;
    a.snd *= b.snd;
    a.fst += b.fst;
    ll g = gcd(a.fst, a.snd);
    a.fst /= g, a.snd /= g;
    return a;
}
 
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    forn(_, t) {
        int n, m;
        cin >> n >> m;
        vector<string> s(n);
        forn(i, n) cin >> s[i];
        vector<vi> adj(n * m);
        int target = -1;
        forn(i, n) forn(j, m) {
            if (s[i][j] == '.') continue;
            if (s[i][j] == 'X') continue;
            if (s[i][j] == 'v') {
                if (i + 1 == n) target = i * m + j;
                else adj[i * m + j].pb((i + 1) * m + j);
                continue;
            }
            if (s[i][j] == '^') {
                if (i == 0) target = i * m + j;
                else adj[i * m + j].pb((i - 1) * m + j);
                continue;
            }
            if (s[i][j] == '<') {
                if (j == 0) target = i * m + j;
                else adj[i * m + j].pb(i * m + j - 1);
                continue;
            }
            if (s[i][j] == '>') {
                if (j + 1 == m) target = i * m + j;
                else adj[i * m + j].pb(i * m + j + 1);
                continue;
            }
            if (s[i][j] == 'S') {
                if (i > 0 && (s[i - 1][j] == 'X' || s[i - 1][j] == '<' || s[i - 1][j] == '>' || s[i - 1][j] == '^')) {
                    adj[i * m + j].pb((i - 1) * m + j);
                }
                if (i + 1 < n && (s[i + 1][j] == 'X' || s[i + 1][j] == '<' || s[i + 1][j] == '>' || s[i + 1][j] == 'v')) {
                    adj[i * m + j].pb((i + 1) * m + j);
                }
                if (j > 0 && (s[i][j - 1] == 'X' || s[i][j - 1] == '<' || s[i][j - 1] == 'v' || s[i][j - 1] == '^')) {
                    adj[i * m + j].pb(i * m + j - 1);
                }
                if (j + 1 < m && (s[i][j + 1] == 'X' || s[i][j + 1] == '>' || s[i][j + 1] == 'v' || s[i][j + 1] == '^')) {
                    adj[i * m + j].pb(i * m + j + 1);
                }
                continue;
            }
            assert(false);
        }
        
        if (target == -1) {
            cout << "0 1\n";
            continue;
        }
        
        vi vis(n * m), deg(n * m);
        dfs(0, adj, vis, deg);
        
        queue<int> q;
        q.push(0); 
        vector<pll> dp(n * m, {0, 1});
        dp[0] = {1, 1};
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            pll prob = {dp[u].fst, dp[u].snd * sz(adj[u])};
            ll g = gcd(prob.fst, prob.snd);
            prob.fst /= g, prob.snd /= g;
            for (int v : adj[u]) {
                dp[v] += prob;
                if (--deg[v] == 0) q.push(v);
            }
        }
        cout << dp[target].fst << " " << dp[target].snd << "\n";
        
    }
    
    return 0;
}
