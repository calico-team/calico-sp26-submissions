#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define ll long long



void solve() {
    int n, m; cin >> n >> m;
    int mtx[n + 1][m + 1];
    for (int i = 1;i <= m; i++)
        mtx[1][i] = 0;
    for (int i = 1; i <= m; i++)
        mtx[2][i] = ((i - 1) % 4) + 1;
    set<int> s; 
    for (int i = 3; i <= n; i++) {
        for (int j = 2; j <= m - 1; j++) {
            s.clear();
            for (int x = 0; x <= 4; x++)
                s.insert(x);
            s.erase(mtx[i-1][j]);
            s.erase(mtx[i-1][j-1]);
            s.erase(mtx[i-1][j+1]);
            s.erase(mtx[i-2][j]);
            mtx[i][j] = *s.begin();
        }
        s.clear();
        for (int x = 0; x <= 4; x++)
            s.insert(x);
        s.erase(mtx[i][2]);
        s.erase(mtx[i][3]);
        s.erase(mtx[i-1][2]);
        mtx[i][1]=*s.begin();
        s.clear();
        for (int x = 0; x <= 4; x++)
            s.insert(x);
        s.erase(mtx[i][m-1]);
        s.erase(mtx[i][m-2]);
        s.erase(mtx[i-1][m-1]);
        mtx[i][m]=*s.begin();
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << mtx[i][j] << ' ';
        }
        cout << endl; 
    }
    cout << endl; 
}




int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while (tt--) solve();
    return 0;
}
