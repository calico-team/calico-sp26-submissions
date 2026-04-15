#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string a, b;
    cin >> a >> b;
    int curr = 0;
    string k = "";
    for (int i = 0; i < a.length(); i++) {
        if (curr == b.length()) {
            k += "#";
            continue;
        }
        if (a[i] == b[curr]) {
            curr++;
            k += a[i];
        }
        else {
            k += "#";
        }
    }
    cout << k << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}