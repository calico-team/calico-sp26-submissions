#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <numeric>
using namespace std;

typedef long long ll;

struct Frac {
    ll num, den;
    Frac(ll n=0, ll d=1) {
        ll g = gcd(abs(n), abs(d));
        num = n / g;
        den = d / g;
        if (den < 0) {
            den *= -1;
            num *= -1;
        }
    }
};

Frac add(Frac a, Frac b) {
    return Frac(a.num * b.den + b.num * a.den, a.den * b.den);
}

Frac divi(Frac a, ll x) {
    return Frac(a.num, a.den * x);
}

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

map<char, pair<int,int>> dir = {
    {'<',{0,-1}}, {'>',{0,1}}, {'^',{-1,0}}, {'v',{1,0}}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<string> g(N);
        for (int i = 0; i < N; i++) cin >> g[i];

        auto inside = [&](int x, int y) {
            return x >= 0 && x < N && y >= 0 && y < M;
        };

        vector<vector<vector<pair<int,int>>>> adj(N, vector<vector<pair<int,int>>>(M));
        vector<vector<int>> indeg(N, vector<int>(M, 0));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                char c = g[i][j];
                if (c == '.' || c == 'X') continue;

                if (dir.count(c)) {
                    auto [dx_, dy_] = dir[c];
                    int ni = i + dx_, nj = j + dy_;

                    if (inside(ni, nj)) {
                        adj[i][j].push_back({ni, nj});
                        indeg[ni][nj]++;
                    }
                }
                else if (c == 'S') {
                    vector<pair<int,int>> valid;

                    for (int d = 0; d < 4; d++) {
                        int ni = i + dx[d];
                        int nj = j + dy[d];
                        if (!inside(ni, nj)) continue;

                        char nc = g[ni][nj];
                        if (nc == '.') continue;

                        if (nc == 'X') {
                            valid.push_back({ni, nj});
                        }
                        else if (dir.count(nc)) {
                            auto [bx, by] = dir[nc];
                            if (ni + bx == i && nj + by == j) continue;
                            valid.push_back({ni, nj});
                        }
                    }

                    for (auto [ni, nj] : valid) {
                        adj[i][j].push_back({ni, nj});
                        indeg[ni][nj]++;
                    }
                }
            }
        }

        vector<vector<Frac>> dp(N, vector<Frac>(M, Frac(0,1)));
        queue<pair<int,int>> q;

        dp[0][0] = Frac(1,1);
        q.push({0,0});

        Frac collected(0,1);

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            Frac cur = dp[x][y];

            char c = g[x][y];

            if (c == 'X') continue;

            if (dir.count(c)) {
                auto [dx_, dy_] = dir[c];
                int nx = x + dx_, ny = y + dy_;
                if (!inside(nx, ny)) {
                    collected = add(collected, cur);
                }
            }

            int k = adj[x][y].size();
            for (auto [nx, ny] : adj[x][y]) {
                Frac send = (c == 'S') ? divi(cur, k) : cur;

                dp[nx][ny] = add(dp[nx][ny], send);

                indeg[nx][ny]--;
                if (indeg[nx][ny] == 0) {
                    q.push({nx, ny});
                }
            }
        }

        cout << collected.num << " " << collected.den << endl;
    }

    return 0;
}