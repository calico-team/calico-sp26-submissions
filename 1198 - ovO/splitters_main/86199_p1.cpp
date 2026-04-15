#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 20 + 7;

int t, n, m, ansp, ansq;

char c[N][N];

int dx[4] = {1,-1, 0, 0};
int dy[4] = {0, 0, 1,-1};

int gcd(int x, int y){
    if(!y) return x;
    return gcd(y, x % y);
}

void dfs(int x, int y, int p, int q, int lstx, int lsty){
    if(x < 1 || x > n || y > m || y < 1){
        // cout << x << ' ' << y << ": " << p << ' ' << q << '\n';
        int grow = q / gcd(ansq, q);
        ansq *= grow, ansp *= grow;
        // cout << ansp << ' ' << ansq << '\n';
        ansp += p * ansq / q;
        int div = gcd(ansp, ansq);
        ansp /= div, ansq /= div;
        return;
    }
    if(c[x][y] == '.' || c[x][y] == 'X') return;
    if(c[x][y] == '>') dfs(x, y + 1, p, q, x, y);
    if(c[x][y] == '<') dfs(x, y - 1, p, q, x, y);
    if(c[x][y] == '^') dfs(x - 1, y, p, q, x, y);
    if(c[x][y] == 'v') dfs(x + 1, y, p, q, x, y);
    if(c[x][y] == 'S'){
        int cnt = 0;
        for(int i = 0; i < 4; i ++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx == lstx && ny == lsty) continue;
            if(c[nx][ny] != '.' && c[nx][ny] != 'S') cnt ++;
        }
        for(int i = 0; i < 4; i ++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx == lstx && ny == lsty) continue;
            if(c[nx][ny] != '.' && c[nx][ny] != 'S'){
                dfs(nx, ny, p, q * cnt, x, y);
            }
        }
    }
}

signed main(){

    cin >> t;

    while(t --){

        cin >> n >> m;

        ansp = 0, ansq = 1;
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= m; j ++)
                cin >> c[i][j];

        dfs(1, 1, 1, 1, -1, -1);

        cout << ansp << ' ' << ansq << '\n';

    }

    return 0;
}

