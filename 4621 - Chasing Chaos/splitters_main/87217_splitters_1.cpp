#include <bits/stdc++.h>
using namespace std;

struct RatioPiece {
    long long top;
    long long bottom;
};

long long fuse_gcd(long long a, long long b) {
    return std::gcd(a, b);
}

RatioPiece add_ratio(RatioPiece a, RatioPiece b) {
    long long g = fuse_gcd(a.bottom, b.bottom);
    long long l = a.bottom / g * b.bottom;
    long long s = a.top * (l / a.bottom) + b.top * (l / b.bottom);
    long long h = fuse_gcd(llabs(s), l);
    return {s / h, l / h};
}

RatioPiece div_ratio(RatioPiece a, long long by) {
    long long g = fuse_gcd(llabs(a.top), by);
    long long nt = a.top / g;
    long long nb = a.bottom * (by / g);
    long long h = fuse_gcd(llabs(nt), nb);
    return {nt / h, nb / h};
}

pair<long long, long long> solve(int N, int M, vector<string>& factory) {
    vector<vector<int>> seen(N, vector<int>(M, 0));
    vector<vector<RatioPiece>> memo(N, vector<RatioPiece>(M, {0, 1}));

    auto inside = [&](int r, int c) {
        return r >= 0 && r < N && c >= 0 && c < M;
    };

    auto conveyor_step = [&](char ch) {
        if (ch == '<') return pair<int, int>{0, -1};
        if (ch == '>') return pair<int, int>{0, 1};
        if (ch == '^') return pair<int, int>{-1, 0};
        return pair<int, int>{1, 0};
    };

    function<RatioPiece(int, int)> walk = [&](int r, int c) -> RatioPiece {
        if (!inside(r, c)) return {1, 1};
        if (seen[r][c]) return memo[r][c];

        seen[r][c] = 1;
        char tile = factory[r][c];

        if (tile == 'X') {
            memo[r][c] = {0, 1};
            return memo[r][c];
        }

        if (tile == '<' || tile == '>' || tile == '^' || tile == 'v') {
            auto [dr, dc] = conveyor_step(tile);
            int nr = r + dr;
            int nc = c + dc;
            if (!inside(nr, nc)) {
                memo[r][c] = {1, 1};
            } else {
                memo[r][c] = walk(nr, nc);
            }
            return memo[r][c];
        }

        vector<pair<int, int>> ways;
        const int rr[4] = {-1, 1, 0, 0};
        const int cc[4] = {0, 0, -1, 1};

        for (int z = 0; z < 4; z++) {
            int nr = r + rr[z];
            int nc = c + cc[z];
            if (!inside(nr, nc)) continue;
            char nxt = factory[nr][nc];
            if (nxt == 'X') {
                ways.push_back({nr, nc});
            } else if (nxt == '<' || nxt == '>' || nxt == '^' || nxt == 'v') {
                auto [dr, dc] = conveyor_step(nxt);
                if (nr + dr == r && nc + dc == c) continue;
                ways.push_back({nr, nc});
            }
        }

        RatioPiece total = {0, 1};
        for (auto [nr, nc] : ways) {
            total = add_ratio(total, walk(nr, nc));
        }
        memo[r][c] = div_ratio(total, (long long)ways.size());
        return memo[r][c];
    };

    RatioPiece ans = walk(0, 0);
    if (ans.top == 0) return {0, 1};
    long long g = fuse_gcd(llabs(ans.top), ans.bottom);
    return {ans.top / g, ans.bottom / g};
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