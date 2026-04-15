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
        int n; cin >> n;
        vector<vector<char>> g1(n, vector<char>(n)), g2(n, vector<char>(n));
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> g1[i][j];
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> g2[i][j];
        int minN = 0, maxN = n * n * n;
        for (int i = 0; i < n; i++)
        {
            int cnt1 = 0, cnt2 = 0;
            for (int j = 0; j < n; j++)
            {
                if (g1[i][j] == '#') cnt1++;
                if (g2[i][j] == '#') cnt2++;
            }
            minN += max(cnt1,cnt2);
        }
        vector<int> deleted(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (g1[i][j] == '.')
                {
                    deleted[i]++; maxN -= n;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (g2[i][j] == '.') maxN -= n - deleted[i];
            }
        }
        cout << maxN << " " << minN << endl;
    }
} 