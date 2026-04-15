#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using ll = long long;

int n, m;
char g[20][20];
bool visited[20][20];
ll mem[20][20];
ll base = 1;

ll dfs(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) {
        return base;
    }

    if (g[x][y] == 'x') {
        return 0;
    }

    if (visited[x][y]) {
        return mem[x][y];
    }

    visited[x][y] = true;
    ll ans = 0;

    if (g[x][y] == 'S') {
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        char w[4] = {'v', '^', '>', '<'};
        
        int k = 0;
        ll sum = 0;
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (g[nx][ny] == 'X' || g[nx][ny] == '<' || g[nx][ny] == '>' || g[nx][ny] == '^' || g[nx][ny] == 'v') {
                    if (g[nx][ny] != w[i]) {
                        k++;
                        sum += dfs(nx, ny);
                    }
                }
            }
        }
        
        ans = sum / k;
    } else {
        int nx = x, ny = y;
        if (g[x][y] == '^') nx--;
        else if (g[x][y] == 'v') nx++;
        else if (g[x][y] == '<') ny--;
        else if (g[x][y] == '>') ny++;
        
        ans = dfs(nx, ny);
    }
    
    return mem[x][y] = ans;
}

void solve() {
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = false;
            mem[i][j] = 0;
        }
    }
    
    ll c = dfs(0, 0);
    
    ll gcd = __gcd(c, base);
    
    cout << (c / gcd) << " " << (base / gcd) << "\n";
}

int main() {
    fastio;

    for (int i = 0; i < 20; i++) {
        base *= 6;
    }

    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
}