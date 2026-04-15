#include <bits/stdc++.h>
using namespace std;
struct Fraction {
    long long p, q; 
    Fraction(long long num = 0, long long den = 1) {
        if (den == 0) { p = 0; q = 1; return; }
        long long g = std::gcd(std::abs(num), std::abs(den));
        p = num / g;
        q = den / g;
        if (q < 0) { 
            p = -p; 
            q = -q; 
        }
    }
    Fraction operator+(const Fraction& o) const {
        long long g = std::gcd(q, o.q);
        long long q1_g = q / g;
        long long q2_g = o.q / g;
        long long num = p * q2_g + o.p * q1_g;
        long long den = q1_g * o.q; 
        return Fraction(num, den);
    }
    Fraction operator*(const Fraction& o) const {
        long long g1 = std::gcd(std::abs(p), o.q);
        long long g2 = std::gcd(std::abs(o.p), q);
        long long num = (p / g1) * (o.p / g2);
        long long den = (q / g2) * (o.q / g1);
        return Fraction(num, den);
    }
};
bool is_conv(char c) {
    return c == '<' || c == '>' || c == '^' || c == 'v';
}
void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;
    vector<string> grid(N);
    for (int i = 0; i < N; ++i) {
        cin >> grid[i];
    }
    auto id = [&](int r, int c) {
        return r * M + c;
    };
    int COLLECTED = N * M;
    vector<vector<pair<int, Fraction>>> adj(N * M + 1);
    vector<int> indegree(N * M + 1, 0);
    queue<int> bq;
    vector<bool> visited(N * M + 1, false);
    bq.push(id(0, 0));
    visited[id(0, 0)] = true;
    while (!bq.empty()) {
        int curr = bq.front();
        bq.pop();
        if (curr == COLLECTED) continue;
        int r = curr / M;
        int c = curr % M;
        char tile = grid[r][c];
        if (tile == 'X' || tile == 'x') {
            continue;
        } else if (is_conv(tile)) {
            int nr = r, nc = c;
            if (tile == '<') nc--;
            else if (tile == '>') nc++;
            else if (tile == '^') nr--;
            else if (tile == 'v') nr++;
            int nxt;
            if (nr >= 0 && nr < N && nc >= 0 && nc < M) {
                nxt = id(nr, nc);
            } else {
                nxt = COLLECTED; 
            }

            adj[curr].push_back({nxt, Fraction(1, 1)});
            indegree[nxt]++;

            if (!visited[nxt]) {
                visited[nxt] = true;
                bq.push(nxt);
            }
        } else if (tile == 'S' || tile == 's') {
            vector<int> valid_neighbors;
            if (r - 1 >= 0) {
                char t = grid[r - 1][c];
                if (t == 'X' || t == 'x' || (is_conv(t) && t != 'v')) 
                    valid_neighbors.push_back(id(r - 1, c));
            }
            if (r + 1 < N) {
                char t = grid[r + 1][c];
                if (t == 'X' || t == 'x' || (is_conv(t) && t != '^')) 
                    valid_neighbors.push_back(id(r + 1, c));
            }
            if (c - 1 >= 0) {
                char t = grid[r][c - 1];
                if (t == 'X' || t == 'x' || (is_conv(t) && t != '>')) 
                    valid_neighbors.push_back(id(r, c - 1));
            }
            if (c + 1 < M) {
                char t = grid[r][c + 1];
                if (t == 'X' || t == 'x' || (is_conv(t) && t != '<')) 
                    valid_neighbors.push_back(id(r, c + 1));
            }
            int k = valid_neighbors.size();
            if (k > 0) {
                Fraction weight(1, k);
                for (int nxt : valid_neighbors) {
                    adj[curr].push_back({nxt, weight});
                    indegree[nxt]++;
                    if (!visited[nxt]) {
                        visited[nxt] = true;
                        bq.push(nxt);
                    }
                }
            }
        }
    }
    queue<int> tq;
    for (int i = 0; i <= N * M; ++i) {
        if (visited[i] && indegree[i] == 0) {
            tq.push(i);
        }
    }
    vector<Fraction> flow(N * M + 1, Fraction(0, 1));
    if (visited[id(0, 0)]) {
        flow[id(0, 0)] = Fraction(1, 1);
    }
    while (!tq.empty()) {
        int u = tq.front();
        tq.pop();
        for (const auto& edge : adj[u]) {
            int v = edge.first;
            Fraction w = edge.second;
            flow[v] = flow[v] + (flow[u] * w);
            indegree[v]--;
            if (indegree[v] == 0) {
                tq.push(v);
            }
        }
    }
    cout << flow[COLLECTED].p << " " << flow[COLLECTED].q << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}