#include <iostream>
#include <string>
#include <vector>
using namespace std;

using i64 = long long;
using str = string;
const i64 ILL = 2167167167167167167;
const int INF = 2100000000;

i64 gcd(i64 a, i64 b){
    while(b){
        a %= b;swap(a, b);
    }
    return a;
}

struct Frac {
    i64 p, q;
    Frac(i64 _p = 0, i64 _q = 1) {
        if (_p == 0) { p = 0; q = 1; }
        else {
            i64 g = gcd(abs(_p), abs(_q));
            p = _p / g; q = _q / g;
        }
    }
};

Frac add(Frac a, Frac b) {
    i64 g = gcd(a.q, b.q);
    i64 lcm = (a.q / g) * b.q;
    i64 res_p = a.p * (b.q / g) + b.p * (a.q / g);
    return Frac(res_p, lcm);
}

Frac mul(Frac a, Frac b) {
    i64 g1 = gcd(a.p, b.q);
    i64 g2 = gcd(b.p, a.q);
    return Frac((a.p / g1) * (b.p / g2), (a.q / g2) * (b.q / g1));
}

int n, m;
vector<str> grid;
vector<vector<Frac>> memo;
vector<vector<bool>> vis;

Frac dfs(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= m) return Frac(1, 1);
    if (vis[r][c]) return memo[r][c];

    Frac res(0, 1);
    char t = grid[r][c];

    switch (t) {
        case '.':
        case 'x':
        case 'X':
            res = Frac(0, 1);
            break;
        case '>': res = dfs(r, c + 1); break;
        case '<': res = dfs(r, c - 1); break;
        case '^': res = dfs(r - 1, c); break;
        case 'v': res = dfs(r + 1, c); break;
        case 's':
        case 'S': {
            int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
            char opp[] = {'v', '^', '>', '<'};
            int cnt = 0;
            Frac sum(0, 1);
            for(int i=0;i<4;i++) {
                int nr = r + dr[i], nc = c + dc[i];
                char nt = grid[nr][nc];
                if(nt == 'x' || nt == 'X' || (nt != opp[i] &&
                     (nt == '>' || nt == '<' || nt == '^' || nt == 'v'))) {
                    sum = add(sum, dfs(nr, nc));
                    cnt++;
                }
            }
            res = mul(sum, Frac(1, cnt));
            break;
        }
    }

    vis[r][c] = true;
    return memo[r][c] = res;
}

int main(){
    int t; cin >> t;
    while(t--) {
        cin >> n >> m;
        grid.assign(n, "");
        for (int i = 0; i < n; i++) cin >> grid[i];

        memo.assign(n, vector<Frac>(m));
        vis.assign(n, vector<bool>(m, false));

        Frac ans = dfs(0, 0);
        cout << ans.p << " " << ans.q << "\n";
    }
    return 0;
}