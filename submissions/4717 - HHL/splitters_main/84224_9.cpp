#include "bits/stdc++.h"

using namespace std;

typedef __int128_t int128;

void print128(int128 n)
{
    if (n == 0) { cout << "0"; return; }
    string s;
    while (n > 0) {
        s += (char)('0' + (n % 10));
        n /= 10;
    }
    for (int i = s.size() - 1; i >= 0; i--) cout << s[i];
}

int N, M;
vector<string> mat;

struct Result
{
    int128 n, d;
};

Result dfs(int r, int c, int128 cur_n, int128 cur_d)
{
    if (r < 0 || r >= N || c < 0 || c >= M)
        return {cur_n, cur_d};

    char t = mat[r][c];
    if (t == '.' || t == 'X')
        return {0, 1};

    if (t == '^') return dfs(r - 1, c, cur_n, cur_d);
    if (t == 'v') return dfs(r + 1, c, cur_n, cur_d);
    if (t == '<') return dfs(r, c - 1, cur_n, cur_d);
    if (t == '>') return dfs(r, c + 1, cur_n, cur_d);

    if (t == 'S')
    {
        vector<pair<int, int>> nxt;
        int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

            char nt = mat[nr][nc];
            if (nt == 'X') nxt.push_back({nr, nc});
            else if (nt == '^' && dr[i] != 1)  nxt.push_back({nr, nc});
            else if (nt == 'v' && dr[i] != -1) nxt.push_back({nr, nc});
            else if (nt == '<' && dc[i] != 1)  nxt.push_back({nr, nc});
            else if (nt == '>' && dc[i] != -1) nxt.push_back({nr, nc});
        }

        if (nxt.empty())
            return {0, 1};

        int128 total_n = 0, total_d = 1;
        int128 branch_d = cur_d * (int128)nxt.size();

        for (auto& p : nxt)
        {
            Result res = dfs(p.first, p.second, cur_n, branch_d);
            int128 g = (total_d > res.d) ? std::gcd((long long)total_d, (long long)res.d) : std::gcd((long long)res.d, (long long)total_d);
            int128 lcm = (total_d / g) * res.d;
            total_n = total_n * (lcm / total_d) + res.n * (lcm / res.d);
            total_d = lcm;

            int128 final_g = (total_n > total_d) ? std::gcd((long long)total_n, (long long)total_d) : std::gcd((long long)total_d, (long long)total_n);
            if (total_n == 0) total_d = 1;
            else { total_n /= final_g; total_d /= final_g; }
        }
        return {total_n, total_d};
    }
    return {0, 1};
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while (T--)
    {
        cin >> N >> M;
        mat.assign(N, "");
        for (int i = 0; i < N; i++) cin >> mat[i];

        Result ans = dfs(0, 0, 1, 1);

        print128(ans.n);
        cout << " ";
        print128(ans.d);
        cout << "\n";
    }
    return 0;
}