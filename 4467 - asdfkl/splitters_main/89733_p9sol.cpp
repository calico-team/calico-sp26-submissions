#include <bits/stdc++.h>
#define int long long
#define vi vector<int>
#define vvi vector<vi>
using namespace std;

int out = 0;

int m, n;

void solve(int x, int y, int income, const vector<string>& f, vector<vector<int>>& q)
{
    if (x < 0 || y < 0 || x >= m || y >= n) {
        out += income;
        return;
    }

    q[x][y] += income;
    // int cur = q[x][y];
    int cur = income;

    char ch = f[x][y];

    if (ch == 'v') {
        solve(x + 1, y, cur, f, q);
    } else if (ch == '>') {
        solve(x, y + 1, cur, f, q);
    } else if (ch == '<') {
        solve(x, y - 1, cur, f, q);
    } else if (ch == '^') {
        solve(x - 1, y, cur, f, q);
    } else if (ch == 'X' || ch == '.') {
        // nothing
    } else { // 'S'
        int nsplit = 0;
        if (y > 0 && f[x][y - 1] != '.' && f[x][y - 1] != '>') {
            nsplit ++;
        }
        if (y < n - 1 && f[x][y + 1] != '.' && f[x][y + 1] != '<') {
            nsplit ++;
        }
        if (x > 0 && f[x - 1][y] != '.' && f[x - 1][y] != 'v') {
            nsplit ++;
        }
        if (x < m - 1 && f[x + 1][y] != '.' && f[x + 1][y] != '^') {
            nsplit ++;
        }

        if (nsplit < 2) {cout << "nsplit < 2" << endl;}
        if (y > 0 && f[x][y - 1] != '.' && f[x][y - 1] != '>') {
            solve(x, y - 1, cur / nsplit, f, q);
        }
        if (y < n - 1 && f[x][y + 1] != '.' && f[x][y + 1] != '<') {
            solve(x, y + 1, cur / nsplit, f, q);
        }
        if (x > 0 && f[x - 1][y] != '.' && f[x - 1][y] != 'v') {
            solve(x - 1, y, cur / nsplit, f, q);
        }
        if (x < m - 1 && f[x + 1][y] != '.' && f[x + 1][y] != '^') {
            solve(x + 1, y, cur / nsplit, f, q);
        }
    }
}

int32_t main()
{
    int T;
    cin >> T;

    while (T--) {
        cin  >> m >> n; 

        vector<string> f(m);
        vector<vector<int>> q(m, vector<int>(n, 0)); // record the quantity

        int s_count = 0;
        for (int i = 0; i < m; ++i) {
            cin >> f[i];
            s_count += count(f[i].begin(), f[i].end(), 'S');
        }

        out = 0;
        int orig = pow(6, s_count);
        solve(0, 0, orig, f, q); // 6^20

        /*
        for (int x = 0; x < M; ++x) {
            for (int y = 0; y < N; ++y) {
                cout << q[x][y] << " ";
            }
            cout << endl;
        }
            */
        
        if (out == 0) {
            cout << 0 << " " << 1 << endl;
        } else {
            while (out % 2 == 0 && orig % 2 == 0) {
                out /= 2;
                orig /= 2;
            }
            while (out % 3 == 0 && orig % 3 == 0) {
                out /= 3;
                orig /= 3;
            }
            cout << out << " " << orig << endl;
        }
        

    }
}