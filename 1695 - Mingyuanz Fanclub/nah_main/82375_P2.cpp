#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, p, r, k, ct = 0; cin >> n >> p >> r >> k;
    vector<int> e(n + 1);
    for(int i = 1; i <= n; ++i) cin >> e[i];
    for(int i = 1; i <= n; ++i){
        if(p < e[i]) return void(cout << "nah i'd lose\n");
        p -= e[i];
        ct++;
        if(ct == k) ct = 0, p += r;
    }
    cout << "nah i'd win\n";
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
}