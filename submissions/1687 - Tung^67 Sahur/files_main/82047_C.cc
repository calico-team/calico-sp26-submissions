#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;
    int j = 0;
    for (int i = 0; i < s.length(); i++) {
        if (j < t.length() && s[i] == t[j]) {
            j++;
        } else {
            s[i] = '#';
        }
    }
    cout << s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}