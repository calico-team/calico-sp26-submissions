#include <bits/stdc++.h>
using namespace std;
#define int long long

const int C = 500, MXN = 1000;

vector<pair<int,int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};

int solve() {
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;

    x1 += C; y1 += C; x2 += C; y2 += C;

    vector<vector<int>> grid(MXN,vector<int>(MXN,0)); // -1 for my, 1 for grass
    queue<pair<int,int>> qA, qB;
    grid[x1][y1] = 1;
    qA.push({x1,y1});
    grid[x2][y2] = -1;
    qB.push({x2,y2});
    
    int tick = 0, cnt = 1;
    while(true) {
        tick++;

        if(tick%2==0) {
            int sz = qA.size();
            for(int k = 0; k < sz; k++) {
                auto [i,j] = qA.front();
                qA.pop();

                for(auto [a,b] : dirs) {
                    int ni = i+a, nj = j+b;
                    if(ni < 0 || nj < 0 || ni >= MXN || nj >= MXN) continue;

                    if(grid[ni][nj] == 0) {
                        grid[ni][nj] = 1;
                        qA.push({ni,nj});
                    }
                }
            }
        }

        if(tick%7==0) {
            int sz = qB.size();
            for(int k = 0; k < sz; k++) {
                auto [i,j] = qB.front();
                qB.pop();

                for(auto [a,b] : dirs) {
                    int ni = i+a, nj = j+b;
                    if(ni < 0 || nj < 0 || ni >= MXN || nj >= MXN) continue;

                    if(grid[ni][nj] == 0) {
                        grid[ni][nj] = -1;
                        qB.push({ni,nj});
                        cnt++;
                    }
                }
            }
        }

        if(qB.empty()) break;

        if(tick>10000) break;
    }
    return cnt;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        cout << solve() << endl;
    }
}