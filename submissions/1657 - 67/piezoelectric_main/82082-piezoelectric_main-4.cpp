#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int p = 2 * (a + b);
        int r = d * p;
        cout << c / r << endl;
    }
}