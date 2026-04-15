#include <bits/stdc++.h>

using namespace std;
using ll = long long;
 
void solve(){
    int L, W, E, R; cin >> L >> W >> E >> R;
    int tmp = R*(L + W)*2;
    cout << (E + tmp - 1)/tmp << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc; cin >> tc;
    while(tc--){
        solve();
    }

    return 0;
}