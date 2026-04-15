#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define nl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1; cin >> t;
    while (t--) {
        int n,m; cin>>n>>m;

        vector<vector<int>> v(n,vector<int>(m));
        v[0][0] = 3;
        v[1][0] = 1;
        v[1][1] = 2;
        v[2][1] = 4;

        for(int i = 0; i < n-2; i++){
            for(int j = 0; j < m-2; j++){
                if(i==0){
                    v[i][j+2] = v[i+2][j+1];
                    v[i+1][j+2] = v[i][j];
                    v[i+2][j+2] = v[i+1][j];
                }else{
                    if(j==0){
                        v[i+2][j] = v[i][j+1];
                        v[i+2][j+1] = v[i][j+2];
                        v[i+2][j+2] = v[i+1][j];
                    }else{
                        v[i+2][j+2] = v[i+1][j];
                    }
                }
            }
        }
        for(auto i: v){
            for(auto j: i){
                cout<<j<<" ";
            }
            cout<<nl;
        }
    }

    return 0;
}