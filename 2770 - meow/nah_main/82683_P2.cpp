#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, p, r, k; cin >> n >> p >> r >> k;
    vector<int> e(n);
    for (int i = 0; i < n; i++) cin >> e[i];
    int cur = 0;
    for (int i : e){
        if (cur == k){
            cur = 0;
            p += r;
        }
        if (p - i < 0){
            cout << "nah i’d lose" << "\n";
            return;
        } else {
            p -= i;
            cur++;
        }
    }
    cout << "nah i’d win" << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--){
        solve();
    }
    return 0;
}