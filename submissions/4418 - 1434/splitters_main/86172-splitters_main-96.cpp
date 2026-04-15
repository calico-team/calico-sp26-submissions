#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void add_frac(ll& p1, ll& q1, ll p2, ll q2) {
    if (p2 == 0) return;
    ll num = p1 * q2 + p2 * q1;
    ll den = q1 * q2;
    ll g = __gcd(num, den);
    p1 = num / g;
    q1 = den / g;
}

pair<ll, ll> solve(int N, int M, vector<string>& G) {
    queue<tuple<int, int, ll, ll>> q;
    q.push({0, 0, 1, 1});

    ll P = 0, Q = 1;
    while (!q.empty()) {
        auto [r, c, p, q_curr] = q.front();
        q.pop();
        if (r < 0 || r >= N || c < 0 || c >= M) {
            add_frac(P, Q, p, q_curr);
            continue;
        }
        char t = G[r][c];
        if (t == '.' || t == 'X') continue;
        if (t == 'S') {
            int dir[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
            char bad[] = {'v', '^', '>', '<'};
            vector<pair<int, int>> valid;
            
            for (int i = 0; i < 4; i++) {
                int nr = r + dir[i], nc = c + dc[i];
                if (nr >= 0 && nr < N && nc >= 0 && nc < M) {
                    if (G[nr][nc] != '.' && G[nr][nc] != bad[i]) {
                        valid.push_back({nr, nc});
                    }
                }
            }
            
            int k = valid.size();
            if (k > 0) {
                ll next_q = q_curr * k;
                ll g = __gcd(p, next_q);
                for (auto& nxt : valid) {
                    q.push({nxt.first, nxt.second, p / g, next_q / g});
                }
            }
        } else {
            int nr = r, nc = c;
            if (t == '^') nr--;
            else if (t == 'v') nr++;
            else if (t == '<') nc--;
            else if (t == '>') nc++;
            q.push({nr, nc, p, q_curr});
        }
    }

    return {P, Q};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) {
        int N, M; cin >> N >> M;
        vector<string> factory(N);
        for (int i = 0; i < N; i++) cin >> factory[i];
        auto [P, Q] = solve(N, M, factory);
        cout << P << " " << Q << "\n";
    }
}
