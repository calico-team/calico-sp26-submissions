#include <bits/stdc++.h>
using namespace std;

#define int long long
int bordx = 800;
int bordy = 800;
void solve()  {
    int xg, yg, xm, ym;
    cin >> xg >> yg >> xm >> ym;
    xg += bordx/2;
    yg += bordy/2;
    xm += bordx/2; 
    ym += bordy/2;
    vector<vector<int>> vis(bordx + 1, vector<int>(bordy + 1, 0));
    for (int i = 0; i < bordx + 1; i++) {
        fill(vis[i].begin(), vis[i].end(), 0);
    }
    priority_queue<pair<pair<int, int>, pair<int, int>>,vector<pair<pair<int, int>, pair<int, int>>>,greater<pair<pair<int, int>, pair<int, int>>>> q; //1 is mycelium, 2 is grass
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    q.push({{0, 1}, {xg, yg}});
    q.push({{0, 2}, {xm, ym}});

    while (!q.empty())  {
        int time = q.top().first.first;
        int type = q.top().first.second;
        int x = q.top().second.first;
        int y = q.top().second.second;
        q.pop();
        if (vis[x][y] == 0)  {
            vis[x][y] = type;
        } else  {
            continue;
        }
        if (x < 0 || x > bordx || y < 0 || y > bordy)  {
            continue;
        }
        //cout << x << ' ' << y << ' ' << time << ' ' << type<< endl;
        for (int i = 0; i < 4; i++)  {
            int curx = x+dx[i];
            int cury = y+dy[i];
            if (curx < 0 || curx > bordx || cury < 0 || cury > bordy)  {
                continue;
            }
            if (vis[curx][cury] == 0)  {
                if (type == 1)  {
                    q.push({{time+2, type}, {curx, cury}});
                } else  {
                    q.push({{time+7, type}, {curx, cury}});
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < bordx + 1; i++) {
        for (int j = 0; j < bordy + 1; j++) {
            //cout << vis[i][j] << ' ';
            if (vis[i][j] == 2) {
                ans += 1;
            }
        }
        //cout << endl;
    }
    cout << ans << endl;
}

signed main()   {
    int t;
    t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}