#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--)
    {
        int x1, y1, x2, y2, temp = 2, result = 1; cin >> x1 >> y1 >> x2 >> y2;
        x1 += 2000; y1 += 2000; x2 += 2000; y2 += 2000;
        vector<vector<bool>> vis(4000, vector<bool>(4000));
        queue<pair<int,int>> s1, s2;
        s1.push({x1,y1}); s2.push({x2,y2});
        vis[x1][y1] = true; vis[x2][y2] = true;
        while (!s2.empty())
        {
            while (temp <= 7)
            {
                temp += 2;
                int sz = s1.size();
                for (int i = 0; i < sz; i++)
                {
                    pair<int,int> p1 = s1.front(); s1.pop();
                    if (!vis[p1.first-1][p1.second])
                    {
                        s1.push({p1.first-1, p1.second}); vis[p1.first-1][p1.second] = true;
                    }
                    if (!vis[p1.first+1][p1.second])
                    {
                        s1.push({p1.first+1, p1.second}); vis[p1.first+1][p1.second] = true;
                    }
                    if (!vis[p1.first][p1.second-1])
                    {
                        s1.push({p1.first, p1.second-1}); vis[p1.first][p1.second-1] = true;
                    }
                    if (!vis[p1.first][p1.second+1])
                    {
                        s1.push({p1.first, p1.second+1}); vis[p1.first][p1.second+1] = true;
                    }
                }
            }
            temp %= 7;
            int sz2 = s2.size();
            for (int i = 0; i < sz2; i++)
            {
                pair<int,int> p2 = s2.front(); s2.pop();
                if (!vis[p2.first-1][p2.second])
                {
                    s2.push({p2.first-1,p2.second}); result++; vis[p2.first-1][p2.second] = true;
                }
                if (!vis[p2.first+1][p2.second])
                {
                    s2.push({p2.first+1,p2.second}); result++; vis[p2.first+1][p2.second] = true;
                }
                if (!vis[p2.first][p2.second-1])
                {
                    s2.push({p2.first,p2.second-1}); result++; vis[p2.first][p2.second-1] = true;
                }
                if (!vis[p2.first][p2.second+1])
                {
                    s2.push({p2.first,p2.second+1}); result++; vis[p2.first][p2.second+1] = true;
                }
            }
        }
        cout << result << endl;
    }
} 