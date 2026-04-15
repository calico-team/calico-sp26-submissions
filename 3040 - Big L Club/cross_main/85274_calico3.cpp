#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n, m; cin >> n >> m;

    int MAXN = 1e3+1;
    vector<vector<int>> grid(MAXN, vector<int>(MAXN));

    for(int i = 0; i < MAXN; ++i){
        for(int j = 0; j < MAXN; ++j)
            grid[i][j] = (7*i + 6*j) % 5;
    }

    for(int i = 0; i < n; ++i){

        for(int j = 0; j < m; ++j){
            cout << grid[i][j] << " ";
        }

        cout << "\n";
    }

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while(t--) solve();
}