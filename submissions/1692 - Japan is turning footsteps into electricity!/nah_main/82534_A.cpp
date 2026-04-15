#include <bits/stdc++.h>

using namespace std;
using ll = long long;
 
void solve(){
    int N, P, R, K; cin >> N >> P >> R >> K;
    bool ans = true;
    for(int i = 1; i <= N; i++){
        int x; cin >> x;
        P -= x;

        if(P < 0) ans = false;
        if(i%K == 0) P += R;
    }

    if(ans) cout << "nah i'd win\n";
    else cout << "nah i'd lose\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc; cin >> tc;
    while(tc--){
        solve();
    }

    return 0;
}