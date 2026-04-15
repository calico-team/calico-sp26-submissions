#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        int n = (int)a.size();
        int m = (int)b.size();
        string res(n, '#');
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (j < m && a[i] == b[j]) {
                res[i] = a[i];
                j++;
            }
        }
        cout << res << '\n';
    }
}