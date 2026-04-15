#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;
using ll = long long;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int k, n, m, p, q; cin >> k >> n >> m >> p >> q;
        vector<pair<int,int>> axis(k);
        map<pair<int,int>, int> ast;
        for (int i = 0; i < k; i++)
        {
            cin >> axis[i].first >> axis[i].second;
            int cnt = min(axis[i].first / q, axis[i].second / p);
            pair<int,int> a2 = {axis[i].first - cnt * q, axis[i].second - cnt / p};
            if (ast[a2] == 0) ast[a2] = i + 1;
            else if (axis[ast[a2]-1].first > axis[i].first) ast[a2] = i + 1;
        }
        int startX = axis[0].first, startY = axis[0].second;
        int a3 = -1;
        for (int i = 1; i < k; i++)
        {
            if (axis[i].first > startX && (axis[i].first - startX) % q == 0 && (axis[i].second - startY) % p
                == 0)
            {
                if (a3 == -1 || axis[i].first < axis[a3].first)
                {
                    a3 = i;
                }
            }
        }
        if (a3 != -1)
        {
            cout << a3 << endl; continue;
        }
        while (true)
        {
            int cnt = min((n - 1 - startX) / q, (m - 1 - startY) / p);
            startX += q * (cnt + 1); startY += p * (cnt+1); startX %= n; startY %= m;
            if (ast[{startX,startY}] != 0)
            {
                cout << ast[{startX,startY}] - 1 << endl; break;
            }
        }
    }
}