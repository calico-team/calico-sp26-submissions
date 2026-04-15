#include <bits/stdc++.h>
 
using namespace std;
 
#define forsn(i, s, n) for (int i = int(s); i < int(n); i++)
#define forn(i, n) forsn(i, 0, n)
#define dforsn(i, s, n) for (int i = int(n) - 1; i >= int(s); i--)
#define dforn(i, n) dforsn(i, 0, n)
 
using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vb = vector<bool>;
using pll = pair<ll, ll>;
using bint = __int128;
 
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
 
#define pb push_back
#define eb emplace_back
 
#define fst first
#define snd second

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

const int MAX_SIZE = 10000;
const int OFFSET = 5000;
 
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    forn(_, t) {
        int x_g, y_g, x_m, y_m;
        cin >> x_g >> y_g >> x_m >> y_m;
        
        x_g += OFFSET, y_g += OFFSET;
        x_m += OFFSET, y_m += OFFSET;
        
        vector<vi> vis(MAX_SIZE, vi(MAX_SIZE, 0));
        
        queue<ii> qGrass, qMicelium;
        qGrass.emplace(x_g, y_g);
        qMicelium.emplace(x_m, y_m);
        vis[x_g][y_g] = vis[x_m][y_m] = 1;
        int iter = 1;
        int ret = 1;
        while (!qMicelium.empty()) {
            if (iter % 2 == 0) {
                queue<ii> qGrassNext;
                while (!qGrass.empty()) {
                    auto [x, y] = qGrass.front();
                    qGrass.pop();
                    forn(dir, 4) {
                        int nx = x + dx[dir], ny = y + dy[dir];
                        if (!vis[nx][ny]) {
                            vis[nx][ny] = 1;
                            qGrassNext.emplace(nx, ny);
                        }
                    }
                }
                swap(qGrass, qGrassNext);
            }
            if (iter % 7 == 0) {
                queue<ii> qMiceliumNext;
                while (!qMicelium.empty()) {
                    auto [x, y] = qMicelium.front();
                    qMicelium.pop();
                    forn(dir, 4) {
                        int nx = x + dx[dir], ny = y + dy[dir];
                        if (!vis[nx][ny]) {
                            vis[nx][ny] = 1, ret++;
                            qMiceliumNext.emplace(nx, ny);
                        }
                    }
                }
                swap(qMicelium, qMiceliumNext);
            }
            iter++;
        }
        
        cout << ret << "\n";
    }
    
    return 0;
}
