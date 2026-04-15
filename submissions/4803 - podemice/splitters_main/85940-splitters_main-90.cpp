#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define eb emplace_back
#define pb push_back
#define vc vector
#define fs first
#define sd second

typedef pair<int, int> pii;
typedef vector<int> vi;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

pii add_frac(int p1, int q1, int p2, int q2) {
    int g = gcd(p1 * q2 + p2 * q1, q1 * q2);
    return {(p1 * q2 + p2 * q1) / g, q1 * q2 / g};
}

vc<pii> split(int i, int j, vc<vc<char>> &grid) {
    vc<pii> ret;
    if (grid[i-1][j] != '.' && grid[i-1][j] != 'v') ret.pb({i-1, j});
    if (grid[i+1][j] != '.' && grid[i+1][j] != '^') ret.pb({i+1, j});
    if (grid[i][j-1] != '.' && grid[i][j-1] != '>') ret.pb({i, j-1});
    if (grid[i][j+1] != '.' && grid[i][j+1] != '<') ret.pb({i, j+1});
    return ret;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vc<vi> p(n, vi(m, 0)), q(n, vi(m, 1)), inc(n, vi(m, 0));
    p[0][0] = 1;

    vc<vc<char>> grid(n, vc<char>(m));
    rep(i, 0, n) rep(j, 0, m) {
        cin >> grid[i][j];
    }

    rep(i, 0, n) rep(j, 0, m) {
        if (grid[i][j] == '.' || grid[i][j] == 'X') continue;

        if (i > 0 && (grid[i-1][j] == 'v' || grid[i-1][j] == 'S' && grid[i][j] != '^'))
            inc[i][j]++;

        if (i < n-1 && (grid[i+1][j] == '^' || grid[i+1][j] == 'S' && grid[i][j] != 'v'))
            inc[i][j]++;

        if (j > 0 && (grid[i][j-1] == '>' || grid[i][j-1] == 'S' && grid[i][j] != '<'))
            inc[i][j]++;

        if (j < m-1 && (grid[i][j+1] == '<' || grid[i][j+1] == 'S' && grid[i][j] != '>'))
            inc[i][j]++;
    }

    int ans_p = 0, ans_q = 1;
    queue<pii> qu;
    qu.push({0,0});
    while (!qu.empty()) {
        pii top = qu.front(); qu.pop();
        // cout << top.fs << " " << top.sd << endl;
        if (grid[top.fs][top.sd] == 'S') {
            vc<pii> choices = split(top.fs, top.sd, grid);
            for (auto &itr : choices) {
                pii res = add_frac(p[itr.fs][itr.sd], q[itr.fs][itr.sd], p[top.fs][top.sd], q[top.fs][top.sd] * sz(choices));
                p[itr.fs][itr.sd] = res.fs, q[itr.fs][itr.sd] = res.sd;

                inc[itr.fs][itr.sd]--;
                if (inc[itr.fs][itr.sd] == 0) qu.push(itr);
            }
        } else {
            pii dest;
            if (grid[top.fs][top.sd] == 'v') {
                dest = {top.fs+1, top.sd};
            } else if (grid[top.fs][top.sd] == '^') {
                dest = {top.fs-1, top.sd};
            } else if (grid[top.fs][top.sd] == '>') {
                dest = {top.fs, top.sd+1};
            } else if (grid[top.fs][top.sd] == '<') {
                dest = {top.fs, top.sd-1};
            } else continue;

            if (dest.fs >= 0 && dest.fs < n && dest.sd >= 0 && dest.sd < m) {
                pii res = add_frac(p[dest.fs][dest.sd], q[dest.fs][dest.sd], p[top.fs][top.sd], q[top.fs][top.sd]);
                p[dest.fs][dest.sd] = res.fs, q[dest.fs][dest.sd] = res.sd;
                
                inc[dest.fs][dest.sd]--;
                if (inc[dest.fs][dest.sd] == 0) qu.push(dest);
            } else {
                pii res = add_frac(ans_p, ans_q, p[top.fs][top.sd], q[top.fs][top.sd]);
                ans_p = res.fs, ans_q = res.sd;
            }
        }
    }

    // rep(i, 0, n) {
    //     rep(j, 0, m) {
    //         cout << p[i][j] << "/" << q[i][j] << " ";
    //     } cout << endl;
    // }
    cout << ans_p << " " << ans_q << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    while (t--) solve();
}