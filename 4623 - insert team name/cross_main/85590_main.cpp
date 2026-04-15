# include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    vector<pair<int, int> > d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int tc;
    cin >> tc;
    for(int tc_ = 0; tc_ < tc; tc_++){
        int n, m;
        cin >> n >> m;
        vector<vector<int> > ans(n, vector<int>(m, -1));
        for(int x = 1; x < n - 1; x++){
            for(int y = 1; y < m - 1; y++){
                ans[x][y] = (2 * x + y + 2) % 5;
            }
        }
        for(int x = 1; x < n - 1; x++){
            for(int y = 1; y < m - 1; y++){
                vector<bool> req(5, true);
                req[ans[x][y]] = false;
                for(int dir = 0; dir < 4; dir++){
                    if(ans[x + d[dir].first][y + d[dir].second] != -1){
                        req[ans[x + d[dir].first][y + d[dir].second]] = false;
                    }
                }
                int pt = 0;
                for(int z = 0; z < 5; z++){
                    if(req[z]){
                        while(ans[x + d[pt].first][y + d[pt].second] != -1){
                            ++pt;
                        }
                        ans[x + d[pt].first][y + d[pt].second] = z;
                        ++pt;
                    }
                }
            }
        }
        ans[0][0] = 0;
        ans[0][m - 1] = 0;
        ans[n - 1][0] = 0;
        ans[n - 1][m - 1] = 0;
        for(int x = 0; x < n; x++){
            for(int y = 0; y < m; y++){
                cout << ans[x][y] << ' ';
            }
            cout << endl;
        }
    }
}
/*
..............
.0123401234...
.2340123401...
.4012340123...
.1234012340...
.3401234012...
etc.
*/