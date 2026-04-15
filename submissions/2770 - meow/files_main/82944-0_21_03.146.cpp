#include <bits/stdc++.h>

using namespace std;

void solve(){
    string a, b; cin >> a >> b;
    string cur = "";
    int idx = 0, sz = b.size();
    for (char c : a){
        if (idx < sz && c == b[idx]){
            cur += c;
            idx++;
        } else cur += "#";
    }
    cout << cur << "\n";
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