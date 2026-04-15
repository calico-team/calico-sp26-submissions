#include <bits/stdc++.h>
using namespace std;

__int128 _gcd(__int128 a, __int128 b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

struct Frac {
    long long p, q;
    Frac() : p(0), q(1) {}
    Frac(long long _p, long long _q) {
        if (_q < 0) { _p = -_p; _q = -_q; }
        long long g = abs((long long)_gcd(abs(_p), abs(_q)));
        p = _p / g;
        q = _q / g;
    }
};


Frac add(Frac a, Frac b) {
    __int128 num = (__int128)a.p * b.q + (__int128)b.p * a.q;
    __int128 den = (__int128)a.q * b.q;
    __int128 g = _gcd(num >= 0 ? num : -num, den);
    return Frac((long long)(num / g), (long long)(den / g));
}


Frac div(Frac a, long long k) {
    __int128 num = a.p;
    __int128 den = (__int128)a.q * k;
    __int128 g = _gcd(num >= 0 ? num : -num, den);
    return Frac((long long)(num / g), (long long)(den / g));
}

int N, M;
vector<string> grid;
bool visited[20][20];
Frac memo[20][20];


Frac dfs(int r, int c) {

    if (r < 0 || r >= N || c < 0 || c >= M) {
        return Frac(1, 1);
    }

    if (visited[r][c]) {
        return memo[r][c];
    }
    
    visited[r][c] = true;
    char tile = grid[r][c];
    

    if (tile == 'x' || tile == '.') {
        memo[r][c] = Frac(0, 1);
    }
    else if (tile == '<') memo[r][c]= dfs(r, c - 1);
    else if (tile == '>') memo[r][c]= dfs(r, c + 1);
    else if (tile == '^') memo[r][c] = dfs(r - 1, c);
    else if (tile == 'v') memo[r][c] = dfs(r + 1, c);
    else if (tile == 'S') {
        vector<pair<int, int>> valid_neighbors;
        
  
        if (r - 1 >= 0) {
            char n = grid[r-1][c];
            if (n == 'x' || n == '^' || n == '<' || n == '>') valid_neighbors.push_back({r - 1, c});
        }

        if (r + 1 < N) {
            char n = grid[r+1][c];
            if (n == 'x' || n == 'v' || n == '<' || n == '>') valid_neighbors.push_back({r + 1, c});
        }

        if (c - 1 >= 0) {
            char n = grid[r][c-1];
            if (n == 'x' || n == '^' || n == 'v' || n == '<') valid_neighbors.push_back({r, c - 1});
        }

        if (c + 1 < M) {
            char n = grid[r][c+1];
            if (n == 'x' || n == '^' || n == 'v' || n == '>') valid_neighbors.push_back({r, c + 1});
        }
        
        Frac sum(0, 1);
        for (auto& nb : valid_neighbors) {
            sum = add(sum, dfs(nb.first, nb.second));
        }

        memo[r][c] = div(sum, valid_neighbors.size());
    }
    
    return memo[r][c];
}



void solve() {

    if (!(cin >> N >> M)) return;
    
    grid.assign(N, "");
    for (int i = 0; i < N; ++i) {
        cin >> grid[i];
    }
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            visited[i][j] = false;
        }
    }

    Frac ans = dfs(0, 0);

    if (ans.p == 0) {
        cout << "0 1\n";
    } else {
        cout << ans.p << " " << ans.q << "\n";
    }
}

int main() {

    int T;
    if (cin >> T){
        while (T--){
            solve();
        }
    }
    return 0;
}