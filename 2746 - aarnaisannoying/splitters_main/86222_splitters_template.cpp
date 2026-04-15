#include <bits/stdc++.h>
using namespace std;

/**
 * Simulate the factory and return the final output as the fraction P / Q.
 *
 * N: number of rows in the factory grid
 * M: number of columns in the factory grid
 * factory: vector of N strings of length M, each character one of '^<>vSX.'
 */
pair<long long, long long> solve(int N, int M, vector<string>& factory) {
    auto gcd = [](long long a, long long b) -> long long {
        while (b) { a %= b; swap(a, b); }
        return a;
    };

    auto addFrac = [&](pair<long long,long long> a, pair<long long,long long> b) -> pair<long long,long long> {
        long long p = a.first * b.second + b.first * a.second;
        long long q = a.second * b.second;
        long long g = gcd(abs(p), abs(q));
        return {p/g, q/g};
    };

    auto mulFrac = [&](pair<long long,long long> a, pair<long long,long long> b) -> pair<long long,long long> {
        long long p = a.first * b.first;
        long long q = a.second * b.second;
        long long g = gcd(abs(p), abs(q));
        return {p/g, q/g};
    };

    auto dirOf = [](char c) -> pair<int,int> {
        if (c == '^') return {-1, 0};
        if (c == 'v') return {1, 0};
        if (c == '<') return {0, -1};
        if (c == '>') return {0, 1};
        return {0, 0};
    };

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    vector<vector<int>> indegree(N, vector<int>(M, 0));

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            char tile = factory[r][c];
            if (tile == '.' || tile == 'X') continue;

            vector<pair<int,int>> targets;
            if (tile == 'S') {
                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
                    char nt = factory[nr][nc];
                    if (nt == 'X') {
                        targets.push_back({nr, nc});
                    } else if (nt == '^' || nt == 'v' || nt == '<' || nt == '>') {
                        auto [ddr, ddc] = dirOf(nt);
                        if (nr + ddr == r && nc + ddc == c) continue;
                        targets.push_back({nr, nc});
                    }
                }
            } else {
                auto [ddr, ddc] = dirOf(tile);
                int nr = r + ddr, nc = c + ddc;
                if (nr >= 0 && nr < N && nc >= 0 && nc < M) {
                    targets.push_back({nr, nc});
                }
            }

            for (auto [nr, nc] : targets) {
                indegree[nr][nc]++;
            }
        }
    }

    vector<vector<pair<long long,long long>>> frac(N, vector<pair<long long,long long>>(M, {0,1}));
    frac[0][0] = {1, 1};

    pair<long long,long long> collected = {0, 1};

    queue<pair<int,int>> topo;
    topo.push({0, 0});

    while (!topo.empty()) {
        auto [r, c] = topo.front(); topo.pop();
        char tile = factory[r][c];
        pair<long long,long long> cur = frac[r][c];

        if (tile == 'X') {
            // consumed, do nothing
        } else if (tile == 'S') {
            vector<pair<int,int>> targets;
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
                char nt = factory[nr][nc];
                if (nt == 'X') {
                    targets.push_back({nr, nc});
                } else if (nt == '^' || nt == 'v' || nt == '<' || nt == '>') {
                    auto [ddr, ddc] = dirOf(nt);
                    if (nr + ddr == r && nc + ddc == c) continue; // points back at splitter
                    targets.push_back({nr, nc});
                }
            }
            long long cnt = (long long)targets.size();
            pair<long long,long long> share = mulFrac(cur, {1, cnt});
            for (auto [nr, nc] : targets) {
                frac[nr][nc] = addFrac(frac[nr][nc], share);
                indegree[nr][nc]--;
                if (indegree[nr][nc] == 0) {
                    topo.push({nr, nc});
                }
            }
        } else {
            // conveyor
            auto [ddr, ddc] = dirOf(tile);
            int nr = r + ddr, nc = c + ddc;
            if (nr < 0 || nr >= N || nc < 0 || nc >= M) {
                collected = addFrac(collected, cur);
            } else {
                frac[nr][nc] = addFrac(frac[nr][nc], cur);
                indegree[nr][nc]--;
                if (indegree[nr][nc] == 0) {
                    topo.push({nr, nc});
                }
            }
        }
    }

    return collected;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<string> factory(N);
        for (int i = 0; i < N; i++) cin >> factory[i];
        auto [P, Q] = solve(N, M, factory);
        cout << P << " " << Q << "\n";
    }
    return 0;
}
