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
    int n; cin >> n;
    vector<int>v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    vector<int>ans(n);
    ans[0] = v[0];
    ans[n - 1] = v[n - 1];
    for(int i = 1; i < n - 1; ++i){
        vector<int>temp;
        temp.push_back(v[i]);
        temp.push_back(ans[i - 1]);
        temp.push_back(v[i + 1]);
        sort(temp.begin(), temp.end());
        ans[i] = temp[1];
    }
    for(int i : ans){
        cout << i << " ";
    }
    cout << "\n";

}
int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while(T--){
        solve();
    }
}