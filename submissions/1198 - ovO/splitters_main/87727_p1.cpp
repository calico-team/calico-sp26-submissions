#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair <int, int> PI;

const int N = 20 + 7;

int in[N][N], pp[N][N], qq[N][N], t, n, m, ansp, ansq;

char c[N][N];

vector <PI> a[N][N];

int dx[4] = {1,-1, 0, 0};
int dy[4] = {0, 0, 1,-1};

int gcd(int x, int y){
    if(!y) return x;
    return gcd(y, x % y);
}

struct str{
    int x, y;
};

void add(int &sp, int &sq, int p, int q){
    int grow = q / gcd(sq, q);
    sq *= grow, sp *= grow;
    sp += p * sq / q;
    int div = gcd(sp, sq);
    sp /= div, sq /= div;
}

queue <str> qu;

void dfs(int x, int y, int p, int q, int lstx, int lsty){
    if(x < 1 || x > n || y > m || y < 1){
        add(ansp, ansq, p, q);
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

bool check(int x, int y, int nx, int ny){
    if(c[x][y] != 'S'){
        if(c[x][y] == '>') return ny == y + 1;
        if(c[x][y] == '<') return ny == y - 1;
        if(c[x][y] == '^') return nx == x - 1;
        if(c[x][y] == 'v') return nx == x + 1;
        return false;
    }
    if(c[nx][ny] == '.' || c[nx][ny] == 'S') return false;
    if(c[nx][ny] == 'X') return true;
    if(c[nx][ny] == '>') return ny != y - 1;
    if(c[nx][ny] == '<') return ny != y + 1;
    if(c[nx][ny] == '^') return nx != x + 1;
    if(c[nx][ny] == 'v') return nx != x - 1;
    return false;
}

signed main(){

    cin >> t;

    while(t --){

        cin >> n >> m;

        ansp = 0, ansq = 1;
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= m; j ++)
                cin >> c[i][j], in[i][j] = pp[i][j] = 0, qq[i][j] = 1;

        int xxx = 0, yyy = 0;
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= m; j ++){
                a[i][j].clear();
                if(c[i][j] == '.' || c[i][j] == 'X') continue;
                // if(c[i][j] != 'S'){
                //     if(c[i][j] == '>') a[i][j].push_back({i, j + 1});
                //     if(c[i][j] == '<') a[i][j].push_back({i, j - 1});
                //     if(c[i][j] == '^') a[i][j].push_back({i - 1, j});
                //     if(c[i][j] == 'v') a[i][j].push_back({i + 1, j});
                //     continue;
                // }
                for(int k = 0; k < 4; k ++){
                    int nx = dx[k] + i, ny = dy[k] + j;
                    // if(i == 1 && j == 9) cout << nx << ' ' << ny << " / ";
                    if(check(i, j, nx, ny)){
                        if(nx < 1 || nx > n || ny > m || ny < 1){
                            // cout << i << ' ' << j << 
                            xxx = i, yyy = j;
                            continue;
                        }
                        a[i][j].push_back({nx, ny});
                        in[nx][ny] ++;
                    }
                }
                // if(i != 3 || j != 1) continue;
                // for(auto [nx, ny] : a[i][j]) cout << nx << ' ' << ny << " / ";
            }
            // cout << '\n';
        }

        // for(int i = 1; i <= n; i ++){
        //     for(int j = 1; j <= m; j ++)
        //         cout << in[i][j] << ' ';
        //     cout << '\n';
        // }

        // dfs(1, 1, 1, 1, -1, -1);

        qu.push({1, 1});
        pp[1][1] = 1;

        while(!qu.empty()){
            int x = qu.front().x, y = qu.front().y;
            int p = pp[x][y], q = qq[x][y];
            qu.pop();
            // cout << x << ' ' << y << ": " << pp[x][y] << ' ' << qq[x][y] << " -> ";
            for(auto [nx, ny] : a[x][y]){
                in[nx][ny] --;
                // cout << nx << ' ' << ny << " / ";
                add(pp[nx][ny], qq[nx][ny], p, q * a[x][y].size());
                if(!in[nx][ny]) qu.push({nx, ny});
            }
            // cout << '\n';
        }
        // cout << xxx << ' ' << yyy << '\n';
        if(xxx && yyy) cout << pp[xxx][yyy] << ' ' << qq[xxx][yyy] << '\n';
        else cout << "0 1\n";

    }

    return 0;
}

