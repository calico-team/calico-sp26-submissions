#include <bits/stdc++.h>
using namespace std;

const int OFF = 100, SZ = 201;
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

void solve() {
    int gx, gy, mx, my; cin >> gx >> gy >> mx >> my;
    vector<vector<int>> board(SZ, vector<int>(SZ, 0));
    vector<pair<int, int>> fg, fm;
    board[gx + OFF][gy + OFF] = 1;
    fg.push_back({gx, gy});
    if (gx != mx || gy != my) {
        board[mx + OFF][my + OFF] = 2;
        fm.push_back({mx, my});
    }
    for (int t = 1; t <= 10000; t++) {
        set<pair<int, int>> sg, sm;
        if (t % 2 == 0) {
            for (auto& p : fg) {
                for (int i = 0; i < 4; i++) {
                    int nx = p.first + dx[i], ny = p.second + dy[i];
                    if (nx >= -100 && nx <= 100 && ny >= -100 && ny <= 100)
                        if (board[nx + OFF][ny + OFF] == 0) sg.insert({nx, ny});
                }
            }
        }
        if (t % 7 == 0) {
            for (auto& p : fm) {
                for (int i = 0; i < 4; i++) {
                    int nx = p.first + dx[i], ny = p.second + dy[i];
                    if (nx >= -100 && nx <= 100 && ny >= -100 && ny <= 100)
                        if (board[nx + OFF][ny + OFF] == 0) sm.insert({nx, ny});
                }
            }
        }
        vector<pair<int, int>> nfg, nfm;
        for (auto& p : sg) {
            board[p.first + OFF][p.second + OFF] = 1;
            nfg.push_back(p);
        }
        for (auto& p : sm) {
            if (board[p.first + OFF][p.second + OFF] == 0) {
                board[p.first + OFF][p.second + OFF] = 2;
                nfm.push_back(p);
            }
        }
        if (t % 2 == 0) fg = nfg;
        if (t % 7 == 0) fm = nfm;
        if (sg.empty() && sm.empty() && (t % 14 == 0)) break;
    }
    int ans = 0;
    for (int i = 0; i < SZ; i++) for (int j = 0; j < SZ; j++) if (board[i][j] == 2) ans++;    
    cout << ans << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}