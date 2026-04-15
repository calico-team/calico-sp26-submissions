#include <bits/stdc++.h>
using namespace std;

typedef __int128_t int128;


int128 _gcd(int128 a, int128 b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}


struct Frac {
    long long p, q;
    Frac(long long _p = -1, long long _q = 1) : p(_p), q(_q) {}
};


Frac add(Frac a, Frac b) {
    if (a.p == 0) return b;
    if (b.p == 0) return a;
    int128 num = (int128)a.p * b.q + (int128)b.p * a.q;
    int128 den = (int128)a.q * b.q;
    int128 g = _gcd(num, den);
    return Frac((long long)(num / g), (long long)(den / g));
}


int N, M;
vector<string> grid;
Frac memo[20][20];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
char ops[] = {'v', '^', '>', '<'}; 

Frac dfs(int r, int c) {

    if (r < 0 || r >= N || c < 0 || c >= M) return Frac(1, 1);
    
    if (memo[r][c].p != -1) return memo[r][c];

    char t = grid[r][c];
    
    
    if (t == 'x' || t == 'X' || t == '.') return memo[r][c] = Frac(0, 1);
    if (t == '<') return memo[r][c] = dfs(r, c - 1);
    if (t == '>') return memo[r][c] = dfs(r, c + 1);
    if (t == '^') return memo[r][c] = dfs(r - 1, c);
    if (t == 'v') return memo[r][c] = dfs(r + 1, c);

 

    if (t == 'S' || t == 's'){
        Frac sum(0, 1);
        int valid_count = 0;
        
        for (int i = 0; i < 4; i++){
            int nr = r + dr[i], nc = c + dc[i];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue; 
            
            char n = grid[nr][nc];
            bool is_destroy = (n == 'x' || n == 'X');
            bool is_conv = (n == '<' || n == '>' || n == '^' || n == 'v');
            

            if (is_destroy || (is_conv && n != ops[i])) {
                sum = add(sum, dfs(nr, nc));
                valid_count++;
            }
        }

        if (valid_count == 0) return memo[r][c] = Frac(0, 1);
        int128 den = (int128)sum.q * valid_count;
        int128 g = _gcd(sum.p, den);
        return memo[r][c] = Frac((long long)(sum.p / g), (long long)(den / g));
    }
    
return memo[r][c] = Frac(0, 1);
}



void solve() {
    if (!(cin >> N >> M)) return;
    
    grid.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> grid[i];
        for (int j = 0; j < M; ++j) {
            memo[i][j] = Frac();
        }
    }
    
    Frac ans = dfs(0, 0);
    cout << ans.p << " " << ans.q << "\n";
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (cin >> T){
        while (T--) solve();
    }
    return 0;
}