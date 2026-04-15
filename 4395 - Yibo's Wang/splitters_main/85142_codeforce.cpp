#include <bits/stdc++.h>
using namespace std;

#define int long long
map<char,pair<int,int>> ma;
void solve()  {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n);
    ma['v'] = {1,0};
    ma['^'] = {-1,0};
    ma['<'] = {0,-1};
    ma['>'] = {0,1};
    for (int i =0 ; i < n; i++)  {
        string s;
        cin >> s;
        grid[i].resize(m);
        for (int j = 0; j < m; j++)  {
            grid[i][j] = s[j];
        }
    }
    queue<pair<pair<int,int>,pair<pair<int,int>,pair<int,int>>>> q; //x, y, p, q where cur prob is p/q
    q.push({{0,0},{{1,1},{-1,-1}}});
    set<char> valid = {'v', '^', '<', '>', 'X'};
    int ansp = 0;
    int ansq = 1;
    vector<vector<bool>> vis(n);
    for (int i = 0; i < n; i++)  {
        vis[i].resize(m);
    }
    while (!q.empty())  {
        int curx = q.front().first.first;
        int cury = q.front().first.second;
        int curp = q.front().second.first.first;
        int curq = q.front().second.first.second;
        int prevx = q.front().second.second.first;
        int prevy = q.front().second.second.second;
        q.pop();
        
        //cout << curx << ' ' << cury << endl;
        if (curx < 0 || curx >= n || cury < 0 || cury >= m)  {
            int curnumx = curp/__gcd(curp, curq);
            int curnumy = curq/__gcd(curp, curq);
            if (ansp == 0)  {
                ansp = curnumx;
                ansq = curnumy;
            } else  {
                int clcm = lcm(ansq,curnumy);
                int temp = ansp*(clcm/ansq) + curnumx*(clcm/curnumy);
                ansq = clcm;
                ansp = temp;
                int gc = __gcd(ansp, ansq);
                ansp /= gc;
                ansq /= gc;
            }
            continue;
        }
        if (grid[curx][cury] == 'S')  {
            int cnt = 0;
            if (valid.find(grid[curx+1][cury]) != valid.end())  cnt++;
            if (valid.find(grid[curx-1][cury]) != valid.end())  cnt++;
            if (valid.find(grid[curx][cury+1]) != valid.end())  cnt++;
            if (valid.find(grid[curx][cury-1]) != valid.end())  cnt++;
            cnt -= 1;
            //cout << "WEOUGBWEUG " << curx << ' ' << cury << ' ' << cnt << endl;
            if (valid.find(grid[curx+1][cury]) != valid.end())  {
                if (!(curx+1 == prevx && cury == prevy))  {
                    q.push({{curx+1, cury}, {{curp, curq*cnt}, {curx, cury}}});
                } 
            }
            if (valid.find(grid[curx-1][cury]) != valid.end())  {
                if (!(curx-1 == prevx && cury == prevy))  {
                    q.push({{curx-1, cury}, {{curp, curq*cnt}, {curx, cury}}});
                } 
            }
            if (valid.find(grid[curx][cury+1]) != valid.end())  {
                if (!(curx == prevx && cury+1 == prevy))  {
                    q.push({{curx, cury+1}, {{curp, curq*cnt}, {curx, cury}}});
                }
            }
            if (valid.find(grid[curx][cury-1]) != valid.end())  {
                if (!(curx == prevx && cury-1 == prevy))  {
                    q.push({{curx, cury-1}, {{curp, curq*cnt}, {curx, cury}}});
                }
            }
        } else if (grid[curx][cury] == 'X')  {
            continue;
        } else if (valid.find(grid[curx][cury]) != valid.end())  {
            int dx = ma[grid[curx][cury]].first;
            int dy = ma[grid[curx][cury]].second;
            q.push({{curx+dx, cury+dy}, {{curp, curq}, {curx, cury}}});
        }
    }
    cout << ansp << ' ' << ansq << endl;
}

signed main()   {
    int t;
    t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}