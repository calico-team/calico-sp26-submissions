#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()

void solve() {
    int N, P, R, K;
    cin >> N >> P >> R >> K; 
    vector<int> E(N);
    for (int &i : E) cin >> i; 

    int defeated = 0; 
    for (int &i : E) {
        P -= i; 
        if (P < 0) {
            cout << "nah i'd lose\n";
            return; 
        }
        defeated++; 
        if (defeated == K) {
            P += R; 
            defeated = 0; 
        }
    }

    cout << "nah i'd win\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t; 
    while(t--)
        solve();
}