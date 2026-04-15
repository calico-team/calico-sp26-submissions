#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        string s;

        for (int i = 0; i < n; i++) {
            cin >> s;
            for (char c : s) if (c == '#') a[i]++;
        }
        for (int i = 0; i < n; i++) {
            cin >> s;
            for (char c : s) if (c == '#') b[i]++;
        }

        long long mx = 0, mn = 0;
        for (int i = 1; i < n; i++) {
            mx += 1LL * a[i] * b[i];
            mn += max(a[i], b[i]);
        }

        cout << mx << ' ' << mn << '\n';
    }
}
