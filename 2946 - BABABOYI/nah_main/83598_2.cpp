#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long N, P, R, K;
    cin >>N >> P>> R >>K;
    
    vector<long long> E(N);
    for (int i = 0; i < N; i++) {
        cin >> E[i];
    }
    
    bool is_winner = true;
    
    for(int i = 0; i < N; i++) {
        P -= E[i];
        if (P <0){
            is_winner = false;
            break;
        }
        if((i + 1) % K ==0){
            P+=R;
        }
    }
    if (is_winner) {
        cout << "nah i'd win\n";
    }else{
        cout << "nah i'd lose\n";
    }
}

int main() {
    int T;
    if (cin >> T){
        while (T--){
            solve();
        }
    }
    return 0;
}