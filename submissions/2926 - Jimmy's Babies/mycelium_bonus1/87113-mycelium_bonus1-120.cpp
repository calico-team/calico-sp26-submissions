#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int OFFSET = 300;
const int SIZE = 2 * OFFSET + 1; 

void solve() {
    int xg, yg, xm, ym; cin >> xg >> yg >> xm >> ym;
    xg += OFFSET; yg += OFFSET;
    xm += OFFSET; ym += OFFSET;

    vector<vector<int>> owner(SIZE, vector<int>(SIZE, -1));
    vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

    vector<pair<int,int>> grass_front, myc_front;
    owner[xg][yg] = 0; grass_front.push_back({xg, yg});
    owner[xm][ym] = 1; myc_front.push_back({xm, ym});

    auto spread = [&](vector<pair<int,int>>& front, int typ) {
        vector<pair<int,int>> next_front;
        
        for (auto [r, c] : front) {
            for (auto [dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < SIZE && nc >= 0 && nc < SIZE && owner[nr][nc] == -1) {
                    owner[nr][nc] = typ;
                    next_front.push_back({nr, nc});
                }
            }
        }
        front = move(next_front); 
    };

    for (int tick = 1; tick <= 500; tick++) {
        if (tick % 2 == 0) spread(grass_front, 0);
        if (tick % 7 == 0) spread(myc_front,   1);
    }

    ll myc_count = 0;
    for (int r = 0; r < SIZE; r++)
        for (int c = 0; c < SIZE; c++)
            if (owner[r][c] == 1) myc_count++;

    cout << myc_count << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while (t--) solve();
}

