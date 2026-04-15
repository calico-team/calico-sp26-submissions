/*
 * it will be better next time :3
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1e18
#define f first
#define s second
#define pii pair<int, int>
#define vi vector<int>

const int MOD = 1'000'000'000 + 7;

void setIO(string name = "")
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#ifdef LOCAL
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    if (!name.empty())
    {
        freopen((name + ".INP").c_str(), "r", stdin);
        freopen((name + ".OUT").c_str(), "w", stdout);
    }
#endif
}

void solve()
{
    int n, m; cin >> n >> m;    
    vector<vi> a(n, vi(m));
    if(n == 3) {
        for(int j = 0; j < m; j++) {
            a[1][j] = (j % 3) + 1;
            if(j & 1) {
                a[0][j] = 4;
                a[2][j] = 0;     
            }
            else {
                a[0][j] = 0;
                a[2][j] = 4;
            }
        }
    }
    else if(m == 3) {
        for(int i = 0; i < n; i++) {
            a[i][1] = (i % 3) + 1;
            if(i & 1) {
                a[i][0] = 4;
                a[i][2] = 0;     
            }
            else {
                a[i][0] = 0;
                a[i][2] = 4;
            }
        }
    }
    else
    {
        a[0][0] = 0;
        a[1][0] = 1;
        a[2][0] = 1;
        a[3][0] = 0;
        a[0][1] = 0;
        a[1][1] = 2;
        a[2][1] = 4;
        a[3][1] = 3;
        a[0][2] = 4;
        a[1][2] = 3;
        a[2][2] = 0;
        a[3][2] = 2;
        a[0][3] = 0;
        a[1][3] = 1;
        a[2][3] = 1;
        a[3][3] = 0;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}

signed main()
{
    setIO();
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}

