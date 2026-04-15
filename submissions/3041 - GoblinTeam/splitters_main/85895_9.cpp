#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

void add(ll &n1, ll &d1, ll n2, ll d2) {
    ll den = d1 / gcd(d1, d2) * d2;
    ll num = n1 * (den / d1) + n2 * (den / d2);
    ll g = gcd(num, den);
    n1 = num / g;
    d1 = den / g;
}

int N, M;
vector<string> g;
ll total_num, total_den;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int get_dir(char c) {
    if (c == '^') return 0;
    if (c == 'v') return 1;
    if (c == '<') return 2;
    return 3;
}

void dfs(int r, int c, ll num, ll den) {
    if (g[r][c] == 'X') return;
    if (g[r][c] == '.') return;
    if (g[r][c] == 'S') {
        vector<pair<int,int>> valid;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if (g[nr][nc] == '.') continue;
            if (g[nr][nc] == 'X') {
                valid.push_back({nr, nc});
                continue;
            }
            int d = get_dir(g[nr][nc]);
            int back_r = nr + dr[d], back_c = nc + dc[d];
            if (back_r == r && back_c == c) continue;
            valid.push_back({nr, nc});
        }
        int k = valid.size();
        for (auto &p : valid) {
            int nr = p.first, nc = p.second;
            if (g[nr][nc] == 'X') continue;
            ll new_num = num, new_den = den * k;
            ll g = gcd(new_num, new_den);
            new_num /= g; new_den /= g;
            dfs(nr, nc, new_num, new_den);
        }
        return;
    }
    int d = get_dir(g[r][c]);
    int nr = r + dr[d], nc = c + dc[d];
    if (nr < 0 || nr >= N || nc < 0 || nc >= M) {
        add(total_num, total_den, num, den);
        return;
    }
    if (g[nr][nc] == '.') return;
    dfs(nr, nc, num, den);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> N >> M;
        g.resize(N);
        for (int i = 0; i < N; i++) cin >> g[i];
        total_num = 0; total_den = 1;
        dfs(0, 0, 1, 1);
        cout << total_num << " " << total_den << "\n";
    }
    return 0;
}