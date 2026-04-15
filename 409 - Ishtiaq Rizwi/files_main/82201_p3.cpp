#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 2e18;

void solve() {
    string S, T;
    cin >> S >> T;
    
    int j = 0;
    
    int n = S.size(), m = T.size();
    
    for (int i = 0;i < n;i ++) {
        if (j < m && S[i] == T[j]) {
            j ++;
        }
        else {
            S[i] = '#';
        }
    }
    
    cout << S << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t --)
        solve();
    return 0;
}