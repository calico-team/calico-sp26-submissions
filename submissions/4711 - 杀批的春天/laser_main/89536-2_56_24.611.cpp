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
            ast[{axis[i].first,axis[i].second}] = i + 1;
        }
        int startX = axis[0].first, startY = axis[0].second;
        while (true)
        {
            startX += q; startY += p; startX %= n; startY %= m;
            if (ast[{startX,startY}] != 0)
            {
                cout << ast[{startX,startY}] - 1 << endl; break;
            }
        }
    }
    return 0;
}