#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

struct Frac {
    ll p, q;

    Frac(ll p_ = 0, ll q_ = 1) {
        p = p_;
        q = q_;
        norm();
    }

    void norm() {
        if (q == 0) {
            p = 0; q = 1; return;
        }
        ll g = ::gcd(p < 0 ? -p : p, q < 0 ? -q : q);
        p /= g;
        q /= g;
        if (q < 0) { p = -p; q = -q; }
    }

    Frac operator+(const Frac& o) const {
        ll g = ::gcd(q, o.q);
        ll lcm = q / g * o.q;
        ll a = p * (lcm / q);
        ll b = o.p * (lcm / o.q);
        return Frac(a + b, lcm);
    }

    Frac operator/(ll k) const {
        return Frac(p, q * k);
    }
};

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };
const char dc[] = { '^', 'v', '<', '>' };

int main() {
    int T;
    cin >> T;
    if (!(T >= 1 && T <= 50)) {
        cout << "The value of T is greater than or equal to 1 and less than or equal to 50.";
        return -1;
    }
    while (T--) {
        int R, C;
        cin >> R >> C;
        if (!(R >= 1 && R <= 15)) {
            cout << "The value of R is greater than or equal to 1 and less than or equal to 15.";
            return -1;
        }
        if (!(C >= 1 && C <= 15)) {
            cout << "The value of C is greater than or equal to 1 and less than or equal to 15.";
            return -1;
        }
        vector<string> g(R);
        for (int i = 0; i < R; ++i) {
            cin >> g[i];
        }

        int n = R * C;
        vector<vector<int> > adj(n);
        vector<int> in_degree(n, 0);

        for (int x = 0; x < R; ++x) {
            for (int y = 0; y < C; ++y) {
                int u = x * C + y;
                char c = g[x][y];
                if (c == '.' || c == 'X') continue;

                if (c == 'S') {
                    vector<int> vs;
                    for (int d = 0; d < 4; ++d) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];
                        if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                        char nc = g[nx][ny];
                        if (nc == '.' || nc == 'S') continue;

                        bool points_back = false;
                        if (nc == '^' && nx - 1 == x && ny == y) points_back = true;
                        else if (nc == 'v' && nx + 1 == x && ny == y) points_back = true;
                        else if (nc == '<' && nx == x && ny - 1 == y) points_back = true;
                        else if (nc == '>' && nx == x && ny + 1 == y) points_back = true;

                        if (points_back) continue;
                        vs.push_back(nx * C + ny);
                    }
                    for (int i = 0; i < vs.size(); ++i) {
                        int v = vs[i];
                        adj[u].push_back(v);
                        in_degree[v]++;
                    }
                }
                else {
                    int d = -1;
                    for (int i = 0; i < 4; ++i) {
                        if (dc[i] == c) {
                            d = i; break;
                        }
                    }
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                    int v = nx * C + ny;
                    adj[u].push_back(v);
                    in_degree[v]++;
                }
            }
        }

        queue<int> q;
        vector<int> topo;
        for (int i = 0; i < n; ++i) {
            if (in_degree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int u = q.front(); q.pop();
            topo.push_back(u);
            for (int i = 0; i < adj[u].size(); ++i) {
                int v = adj[u][i];
                in_degree[v]--;
                if (in_degree[v] == 0) q.push(v);
            }
        }

        vector<Frac> dp(n, Frac(0, 1));
        dp[0] = Frac(1, 1);
        Frac ans(0, 1);

        for (int i = 0; i < topo.size(); ++i) {
            int u = topo[i];
            int x = u / C;
            int y = u % C;
            char c = g[x][y];
            Frac f = dp[u];
            if (f.p == 0) continue;

            if (c == 'X' || c == '.') continue;

            if (c == 'S') {
                int cnt = adj[u].size();
                Frac add = f / cnt;
                for (int j = 0; j < adj[u].size(); ++j) {
                    int v = adj[u][j];
                    dp[v] = dp[v] + add;
                }
            }
            else {
                int d = -1;
                for (int j = 0; j < 4; ++j) {
                    if (dc[j] == c) { d = j; break; }
                }
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
                    ans = ans + f;
                }
                else {
                    int v = nx * C + ny;
                    dp[v] = dp[v] + f;
                }
            }
        }

        cout << ans.p << " " << ans.q << endl;
    }
    return 0;
}