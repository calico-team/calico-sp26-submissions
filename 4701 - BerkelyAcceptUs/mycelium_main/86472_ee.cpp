#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
int MV = 1e18;
vector<array<int, 2>> d = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
int o = 300;

void solve(){
    int xg, yg, xm, ym;
    cin >> xg >> yg >> xm >> ym;
    vector<vector<int>> grid(1000, vector<int>(1000));
    deque<array<int, 4>> dq;
    dq.pb({xg+o, yg+o, 1, 1});
    dq.pb({xm+o, ym+o, 1, 2});
    grid[xg+o][yg+o] = 1;
    grid[xm+o][ym+o] = 2;
    int res = 1;
    while(!dq.empty()){
        auto[x, y, time, t] = dq.front();
        dq.pop_front();
        if(time % 2 == 0 && t == 1 || time % 7 == 0 && t == 2){
            for(auto[dx, dy]: d){
                int nx = x+dx;
                int ny = y+dy;
                if(grid[nx][ny] == 0 && nx >= 0 && nx < 1000 && ny >= 0 && ny < 1000){
                    grid[nx][ny] = t;
                    dq.pb({nx, ny, time+1, t});
                    if(t == 2) res++;
                }
            }
        } else{
            dq.pb({x, y, time+1, t});
        }
    }
    cout << res << '\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}