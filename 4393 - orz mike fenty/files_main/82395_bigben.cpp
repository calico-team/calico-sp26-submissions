#include <bits/stdc++.h>
using namespace std;

int t;
string a, b;

void solve() {
    cin >> a >> b;
    int pos = 0;
    string ans = "";
    for(int i = 0; i < b.size(); i++) {
        char cur = b[i];
        while(a[pos] != cur) {
            ans += '#';
            pos++;
        }
        ans += a[pos];
        pos++;
    }

    cout << ans << "\n";
}

int main() {
    cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
}