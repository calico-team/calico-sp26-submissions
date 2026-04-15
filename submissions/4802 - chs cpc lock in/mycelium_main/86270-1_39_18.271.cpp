#include <bits/stdc++.h>
using namespace std;
#define int long long
using vi = vector<int>;
using ll = long long;
using str = string;
using pi = pair<int,int>;
using vb = vector<bool>;

#define sz(x) int(size(x))
#define lb lower_bound
#define ub upper_bound
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
const int MOD = 1000000000;
const int INF = 1e18;


void solve() {
    int xg, yg, xm, ym; cin >> xg >> yg >> xm >> ym;
    xg += 150, yg += 150, xm += 150, ym += 150;

    vector<vector<array<int,2>>> g(301, vector<array<int,2>> (301));
    


    g[xg][yg] = {1, 0};
    g[xm][ym] = {2, 0};

    set<int> crt;
    for (int i = 2; i <= 200; i += 2) crt.insert(i);
    for (int i = 7; i <= 200; i += 2) crt.insert(i);

    for (int t : crt) {
        for (int i = 1; i < 300; i++) {
            for (int j = 1; j < 300; j++) {
                if (t % 2 == 0) {
                    if (g[i][j][0] == 0 and ((g[i-1][j][0] == 1 and g[i-1][j][1] != t) or (g[i+1][j][0] == 1 and g[i+1][j][1] != t) or (g[i][j-1][0] == 1 and g[i][j-1][1] != t) or (g[i][j+1][0] == 1 and g[i][j+1][1] != t))) g[i][j] = {1, t};
                }
                if (t % 7 == 0) {
                    if (g[i][j][0] == 0 and ((g[i-1][j][0] == 2 and g[i-1][j][1] != t) or (g[i+1][j][0] == 2 and g[i+1][j][1] != t) or (g[i][j-1][0] == 2 and g[i][j-1][1] != t) or (g[i][j+1][0] == 2 and g[i][j+1][1] != t))) g[i][j] = {2, t};
                }
            }
        }
    }

    int ct = 0;
    for (int i = 0; i <= 300; i++) {
        for (int j = 0; j <= 300; j++) {
            //cout << g[i][j][0] << " ";
            if (g[i][j][0] == 2) ct++;
        }
    }

    cout << ct << '\n';
    

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}


