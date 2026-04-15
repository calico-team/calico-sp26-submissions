#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b, w, r;
    cin >> a >> b >> w >> r;
    long long k = 2 * (a + b) * r;
    if (w % k == 0) {
        cout << w / k << '\n';
    }
    else {
        cout << (w / k) + 1 << '\n';
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}