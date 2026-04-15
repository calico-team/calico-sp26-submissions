#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

struct frac {
    ll p, q;
    
    void red() {
        if (p == 0) { q = 1; return; }
        ll g = gcd(p, q);
        p /= g; q /= g;
    }

    void add(frac other) {
        if (other.p == 0) return;
        if (p == 0) {
            p = other.p;
            q = other.q;
            return;
        }
        ll common_q = (q * other.q) / gcd(q, other.q);
        p = p * (common_q / q) + other.p * (common_q / other.q);
        q = common_q;
        red();
    }
};

char g[20][20];
int N, M;

frac solve(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= M) return {1, 1};
    
    if (g[r][c] == 'X' || g[r][c] == '.') return {0, 1};
    
    if (g[r][c] == 'S') {
        int k = 0;
        frac total_prob = {0, 1};
        int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
        char rev[] = {'v', '^', '>', '<'};
        
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i], nc = c + dc[i];
            bool ok = false;
            
            if (nr < 0 || nr >= N || nc < 0 || nc >= M) {
                ok = false;
            } else if (g[nr][nc] == 'X') {
                ok = true;
            } else if (string("^v<>").find(g[nr][nc]) != string::npos && g[nr][nc] != rev[i]) {
                ok = true;
            }
            
            if (ok) {
                k++;
                frac res = solve(nr, nc);
                total_prob.add(res);
            }
        }
        
        if (k > 0) {
            total_prob.q *= k;
            total_prob.red();
        }
        return total_prob;
    }
    
    int nr = r, nc = c;
    if (g[r][c] == '^') nr--;
    else if (g[r][c] == 'v') nr++;
    else if (g[r][c] == '<') nc--;
    else if (g[r][c] == '>') nc++;
    
    return solve(nr, nc);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        cin >> N >> M;
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cin >> g[i][j];
            }
        }

        frac ans = solve(0, 0);
        cout << ans.p << " " << ans.q << "\n";
    }
    
    return 0;
}