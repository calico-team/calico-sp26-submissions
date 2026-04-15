#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4;
int T, N, P, R, K, E[MM+1];

void solve(){
    cin >> N >> P >> R >> K;
    for (int i = 1; i <= N; i++) cin >> E[i];
    for (int i = 1; i <= N; i++){
        if (((i-1)%K) == 0 && i != 1) P += R;
        if (E[i] > P){
            cout << "nah i'd lose\n";
            return;
        }
        P -= E[i];
    }
    cout << "nah i'd win\n";
}

int main(){
    cin >> T;
    for (; T > 0; T--) solve();
}