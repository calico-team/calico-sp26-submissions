#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin >> n;
    int a, b, c; cin >> a >> b >> c;
    int num = a + b + c - min({a, b, c}) - max({a, b, c});
    for (int i = 0; i < 3; i++) cout << num << " ";
    cout << "\n";
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