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
    xg += 1250, yg += 1250, xm += 1250, ym += 1250;

    vector<vector<int>> g(2501, vector<int> (2501));

    vector<vector<bool>> mrk1(2501, vector<bool> (2501));
    vector<vector<bool>> mrk2(2501, vector<bool> (2501));


    g[xg][yg] = 1;
    g[xm][ym] = 2;

    queue<array<int,3>> cg;
    queue<array<int,3>> cm;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (abs(i) == abs(j)) continue;
            cg.push({xg + i, yg + j});
            cm.push({xm + i, ym + j});
        }
    }

    set<int> crt;
    for (int i = 2; i <= 2200; i += 2) crt.insert(i);
    for (int i = 7; i <= 2200; i += 7) crt.insert(i);

    for (int t : crt) {
        
        if (t % 2 == 0) {
            while (!cg.empty() and cg.front()[2] != t) {
                auto pt = cg.front(); cg.pop();
                if (g[pt[0]][pt[1]] == 0) g[pt[0]][pt[1]] = 1;
                else continue;

                for (int i = -1; i <= 1; i++) {
                    for (int j = -1; j <= 1; j++) {
                        if (abs(i) == abs(j)) continue;
                        if (!mrk1[pt[0] + i][pt[1] + j] and g[pt[0] + i][pt[1] + j] == 0) {
                            cg.push({pt[0] + i, pt[1] + j, t});
                            mrk1[pt[0] + i][pt[1] + j] = true;
                        }
                    }
                }

            }
        }

        if (t % 7 == 0) {

            while (!cm.empty() and cm.front()[2] != t) {
                auto pt = cm.front();
                cm.pop();

                if (g[pt[0]][pt[1]] == 0) g[pt[0]][pt[1]] = 2;
                else continue;

                for (int i = -1; i <= 1; i++) {
                    for (int j = -1; j <= 1; j++) {
                        if (abs(i) == abs(j)) continue;
                        if (!mrk2[pt[0] + i][pt[1] + j] and g[pt[0] + i][pt[1] + j] == 0) {
                            cm.push({pt[0] + i, pt[1] + j, t});
                            mrk2[pt[0] + i][pt[1] + j] = true;
                        }
                    }
                }
            }
        }

        
    }


    int ct = 0;
    for (int i = 0; i < 2501; i++) {
        for (int j = 0; j < 2501; j++) {
            //cout << g[i][j] << " ";
            if (g[i][j] == 2) ct++;
        }
        //cout << endl;
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






