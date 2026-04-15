#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool dfs(int u, vector<vector<int>>& g, vector<int>& vis, vector<int>& match) {
    for (int v : g[u]) {
        if (!vis[v]) {
            vis[v] = 1;
            if (match[v] == -1 || dfs(match[v], g, vis, match)) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int max_match(int n, int m, vector<vector<int>>& g) {
    vector<int> match(m, -1);
    int res = 0;
    for (int i = 0; i < n; i++) {
        vector<int> vis(m);
        if (dfs(i, g, vis, match)) res++;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<string> s1(N), s2(N);
        for (int i = 0; i < N; i++) cin >> s1[i];
        for (int i = 0; i < N; i++) cin >> s2[i];

        vector<vector<int>> cnt1(N, vector<int>(N));
        vector<vector<int>> cnt2(N, vector<int>(N));

        ll max_vol = 0;
        for (int z = 0; z < N; z++) {
            int c1 = 0, c2 = 0;
            for (int y = 0; y < N; y++) if (s1[y][z] == '#') c1++;
            for (int x = 0; x < N; x++) if (s2[x][z] == '#') c2++;
            max_vol += 1LL * c1 * c2;
        }

        ll min_vol = 0;
        for (int z = 0; z < N; z++) {
            vector<int> Y, X;
            for (int y = 0; y < N; y++)
                if (s1[y][z] == '#') Y.push_back(y);
            for (int x = 0; x < N; x++)
                if (s2[x][z] == '#') X.push_back(x);

            int ny = Y.size(), nx = X.size();
            vector<vector<int>> g(ny);
            for (int i = 0; i < ny; i++) {
                int y = Y[i];
                for (int j = 0; j < nx; j++) {
                    int x = X[j];
                    if (s1[y][z] == '#' && s2[x][z] == '#') {
                        g[i].push_back(j);
                    }
                }
            }
            min_vol += max_match(ny, nx, g);
        }

        cout << max_vol << " " << min_vol << "\n";
    }
    return 0;
}