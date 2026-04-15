#include <iostream>
#include <string>

using namespace std;

void solve() {
    string a, b;
    if (!(cin >> a >> b)) return;
    int cur = 0;
    string res = "";
    for (char c : a) {
        if (cur < b.size() && c == b[cur]) {
            res += c;
            cur++;
        } else {
            res += '#';
        }
    }
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    if (cin >> t) {
        while (t--) solve();
    }
    return 0;
}