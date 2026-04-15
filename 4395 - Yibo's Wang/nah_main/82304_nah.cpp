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
bool solve(){
    int n, p, r, k;
    cin >> n >> p >> r >> k;
    bool cooked = false;
    for(int i = 1; i <= n; ++i){
        int x; cin >> x;
        p -= x;
        if(p < 0){
            cooked = true;
        }
        if(i % k == 0){
            p += r;
        }
    }
    return !cooked;
}
int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while(T--){
        if(solve()){
            cout << "nah i'd win\n";
        } else{
            cout << "nah i'd lose\n";
        }
    }
}