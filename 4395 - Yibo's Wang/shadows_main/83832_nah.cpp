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
using namespace std;
#define int long long
#define pii pair<int,int>
int INF = 1e18;

int n;
pii findmax(vector<string>g1, vector<string>g2){
    vector<int>dark(n + 1);
    auto dark2 = dark;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            dark[i] += (g1[i][j] == '#');
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            dark2[i] += (g2[i][j] == '#');
        }
    }
    int ans = 0;
    int ans2 = 0;
    for(int i = 1; i <= n; ++i){
        ans += max(dark2[i], dark[i]);
        ans2 += min(n * n, dark[i] * dark2[i]);
    }

    return {ans, ans2};

}

void solve(){
    cin >> n;
    auto readin = [&](vector<string>& v){
        for(int i = 1; i <= n; ++i){
            v[i] = '0';
            string s; cin >> s;
            v[i] += s;
        }
        };
    auto inverted = [&](vector<string>& v, vector<string>& inv){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(v[i][j] == '.'){
                    inv[i][j] = '#';
                } else{
                    inv[i][j] = '.';
                }
            }
        }
        };
    vector<string>v1(n + 1), v2(n + 1), inv1(n + 1), inv2(n + 1);
    readin(v1), readin(v2);

    auto [a, b] = findmax(v1, v2);
    cout << b << " " << a << "\n";
}
int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while(T--){
        solve();
    }
}