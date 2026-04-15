#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<iomanip>
#include <cassert>
#include<algorithm>
#include<queue>
#include <array>
#include<queue>
#include <bitset>
#include<numeric>
using namespace std;
#define int long long
#define pii pair<int,int>
int INF = 1e18;
int k, n, m;
void solve(){
    cin >> n >> m;
    vector<vector<int>>v(n, vector<int>(m));
    vector<int>lol = {2, 0, 3, 1, 4};
    for(int i = 0; i < n; ++i){
        v[i][0] = lol[i % 5];
        cout << v[i][0] << " ";
        for(int j = 1; j < m; ++j){
            v[i][j] = (v[i][j - 1] + 1) % 5;
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }



}
int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while(T--){
        solve();
    }
}