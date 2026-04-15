// ﷽
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;

        ll mi = 0;
        ll ma = n * n * n;

        vector<vector<char>> grid1(n, vector<char>(n));
        vector<vector<char>> grid2(n, vector<char>(n));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> grid1[i][j];
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> grid2[i][j];
            }
        }

        vector<ll> used(n, 0), used2(n, 0);
        ll z = 0;

        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid1[row][col] == '.'){
                    used[row]++;
                    ma -= n;
                }
            }
        }

        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid2[row][col] == '.'){
                    ma -= n;
                    ma += used[row];
                } else {
                    used2[row]++;
                }
            }
        }

        for(int i = 0; i < n; i++){
            mi += max(n - used[i], used2[i]);
        }

        cout << ma << " " << mi - z << "\n";
    }

    return 0;
}