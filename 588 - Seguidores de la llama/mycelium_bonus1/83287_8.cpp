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
 
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    forn(_, t) {
        int x_g, y_g, x_m, y_m;
        cin >> x_g >> y_g >> x_m >> y_m;
        
        set<ii> grass = {{x_g, y_g}}, micelium = {{x_m, y_m}};
        
        queue<ii> qGrass, qMicelium;
        qGrass.emplace(x_g, y_g);
        qMicelium.emplace(x_m, y_m);
        int iter = 1;
        while (!qMicelium.empty()) {
            if (iter % 2 == 0) {
                queue<ii> qGrassNext;
                while (!qGrass.empty()) {
                    auto [x, y] = qGrass.front();
                    qGrass.pop();
                    forn(dir, 4) {
                        int nx = x + dx[dir], ny = y + dy[dir];
                        if (!grass.count({nx, ny}) && !micelium.count({nx, ny})) {
                            grass.emplace(nx, ny);
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
                        if (!grass.count({nx, ny}) && !micelium.count({nx, ny})) {
                            micelium.emplace(nx, ny);
                            qMiceliumNext.emplace(nx, ny);
                        }
                    }
                }
                swap(qMicelium, qMiceliumNext);
            }
            iter++;
        }
        
        cout << sz(micelium) << "\n";
    }
    
    return 0;
}
