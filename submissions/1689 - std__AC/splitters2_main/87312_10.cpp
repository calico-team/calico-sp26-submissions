#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 700;
int t, a, b, p;

signed main() {
    cin >> t;
    while (t--) {
        cin >> a >> b >> p;
        string anss[3];
        while (a--) {
            anss[0] += "..";
            anss[1] += ">S";
            anss[2] += ".X";
        }
        while (b--) {
            anss[0] += ".X";
            anss[1] += ">S";
            anss[2] += ".X";
        }
        for (int i = 0; i <= __lg(p); i++) {
            if (p & 1ll << i) anss[0] += ".^";
            else anss[0] += "..";
            anss[1] += ">S";
            anss[2] += ">^";
        }
        anss[0][0] = 'v';
        anss[0] += '.';
        anss[1] += 'X';
        anss[2] += '.';
        cout << "3 " << anss[0].size() << endl;
        for (int i = 0; i < 3; i++) {
            cout << anss[i] << endl;
        }
    }
    return 0;
}