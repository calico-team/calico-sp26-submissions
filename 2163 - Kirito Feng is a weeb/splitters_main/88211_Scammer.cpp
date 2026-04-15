#include <bits/stdc++.h>
using namespace std;
// waiwaiwai so racist
typedef __int128_t int128;
int128 gcd(int128 a,int128 b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
struct Frac {
    int128 p, q;
    Frac(int128 _p = 0, int128 _q = 1) {
        p = _p;
        q = _q;
        simpl();
    }
    void simpl() {
        if (q < 0) { p = -p; q = -q; }
        if (p == 0) { q = 1; return; }
        int128 a = p < 0 ? -p : p;
        int128 b = q;
        int128 g = gcd(a, b);
        p /= g;
        q /= g;
    }
    Frac operator+(const Frac& o) const {
        if (p == 0) return o;
        if (o.p == 0) return *this;
        int128 g = gcd(q, o.q);
        int128 lcm = (q / g) * o.q;
        int128 num = p * (lcm / q) + o.p * (lcm / o.q);
        return Frac(num, lcm);
    }
    Frac operator/(const int& val) const {
        return Frac(p, q * val);
    }

};

void print_int128(int128 x) {
    if (x == 0) {
        cout << 0;
        return;
    }
    if (x < 0) {
        cout << "-";
        x = -x;
    }
    string s;
    while (x > 0) {
        s += (char)('0' + (x % 10));
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;

}

int N,M;
vector<string> g;
const int MM = 20;
bool vis[MM][MM];
Frac mem[MM][MM];


bool f(int sr, int sc, int nr, int nc) {
    char c = g[nr][nc];
    if (c == 'x' || c == 'X')return true;
    if (c == '<')return !(nr == sr && nc - 1 == sc);
    if (c == '>')return !(nr == sr && nc + 1 == sc);
    if (c == '^')return !(nr - 1 == sr && nc == sc);
    if (c == 'v' || c == 'V')return !(nr + 1 == sr && nc == sc);
    return false;
}
Frac dfs(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= M) {
        return Frac(1, 1);
    }
    if (vis[r][c]) return mem[r][c];
    
    char ch = g[r][c];
    Frac res(0, 1);
    
    if (ch == 'x' || ch == 'X' || ch == '.'){
        res = Frac(0, 1);
    } else if (ch == '<') {
        res = dfs(r, c - 1);
    } else if (ch == '>') {
        res = dfs(r, c + 1);
    } else if (ch == '^') {
        res = dfs(r - 1, c);
    } else if (ch == 'v' || ch == 'V') {
        res = dfs(r + 1, c);
    } else if (ch == 's' || ch == 'S') {
        int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
        int vcnt = 0;
        Frac sum(0, 1);
        
        for (int i = 0; i < 4;++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (f(r ,c, nr, nc)) {
                vcnt++;
                sum = sum + dfs(nr, nc);
            }
        }
        if (vcnt > 0) {
            res = sum / vcnt;
        }
    }
    
    vis[r][c] = true;
    return mem[r][c]= res;
}

void solve() {
    cin >>N >> M;
    g.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> g[i];
        for (int j = 0; j < M; ++j) {
            vis[i][j] = false;
        }
    }
    
    Frac ans = dfs(0, 0);
    
    print_int128(ans.p);
    cout <<" ";
    print_int128(ans.q);
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}