#include <bits/stdc++.h>
using namespace std;
using ll = long long;


struct HopcroftKarp {
    vector<vector<int>> adj;
    vector<int> pair_u, pair_v, dist;
    int n, m;

    HopcroftKarp(int n, int m) : n(n), m(m) {
        adj.resize(n);
        pair_u.assign(n, -1);
        pair_v.assign(m, -1);
        dist.resize(n);
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v);
    }

    bool bfs() {
        queue<int> q;
        for (int u = 0; u < n; u++) {
            if (pair_u[u] == -1) {
                dist[u] = 0;
                q.push(u);
            } else {
                dist[u] = INT_MAX;
            }
        }
        int dist_inf = INT_MAX;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (dist[u] < dist_inf) {
                for (int v : adj[u]) {
                    if (pair_v[v] == -1) {
                        dist_inf = dist[u] + 1;
                    } else if (dist[pair_v[v]] == INT_MAX) {
                        dist[pair_v[v]] = dist[u] + 1;
                        q.push(pair_v[v]);
                    }
                }
            }
        }
        return dist_inf != INT_MAX;
    }

    bool dfs(int u) {
        for (int v : adj[u]) {
            if (pair_v[v] == -1 || (dist[pair_v[v]] == dist[u] + 1 && dfs(pair_v[v]))) {
                pair_u[u] = v;
                pair_v[v] = u;
                return true;
            }
        }
        dist[u] = INT_MAX;
        return false;
    }

    int max_matching() {
        int result = 0;
        while (bfs()) {
            for (int u = 0; u < n; u++) {
                if (pair_u[u] == -1) {
                    if (dfs(u)) {
                        result++;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<string> S1(N), S2(N);
        for (int i = 0; i < N; i++) {
            cin >> S1[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> S2[i];
        }


        ll max_vol = 0;

        vector<vector<bool>> s1_has(N, vector<bool>(N, false)); // s1[y][z]
        vector<vector<bool>> s2_has(N, vector<bool>(N, false)); // s2[x][z]
        vector<int> cnt1(N, 0), cnt2(N, 0);
        for (int y = 0; y < N; y++) {
            for (int z = 0; z < N; z++) {
                if (S1[y][z] == '#') {
                    s1_has[y][z] = true;
                    cnt1[z]++;
                }
            }
        }
        for (int x = 0; x < N; x++) {
            for (int z = 0; z < N; z++) {
                if (S2[x][z] == '#') {
                    s2_has[x][z] = true;
                    cnt2[z]++;
                }
            }
        }

        for (int z = 0; z < N; z++) {
            max_vol += 1LL * cnt1[z] * cnt2[z];
        }

        ll min_vol = 0;
        for (int z = 0; z < N; z++) {

            vector<int> ys, xs;
            for (int y = 0; y < N; y++) {
                if (s1_has[y][z]) ys.push_back(y);
            }
            for (int x = 0; x < N; x++) {
                if (s2_has[x][z]) xs.push_back(x);
            }
            int n = ys.size(), m = xs.size();
            if (n == 0 || m == 0) continue; 
            HopcroftKarp hk(n, m);
            for (int yi = 0; yi < n; yi++) {
                int y = ys[yi];
                for (int xi = 0; xi < m; xi++) {
                    int x = xs[xi];
                    hk.add_edge(yi, xi);
                }
            }
            min_vol += hk.max_matching();
        }

        cout << max_vol << " " << min_vol << "\n";
    }
    return 0;
}