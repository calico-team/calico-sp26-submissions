#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        string ans = "";
        cin >> a >> b;
        int i = 0, j = 0;
        while (i < a.size()) {
            if (j >= b.size() || b[j] != a[i]) {
                ans += "#";
            }
            else {
                ans += b[j];
                j++;
            }
            i++;
        }
        cout << ans << "\n";
    }
}