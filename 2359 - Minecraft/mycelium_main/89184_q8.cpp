#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll XG, YG, XM, YM;
    cin >> XG >> YG >> XM >> YM;
    ll count = 0;
    ll max_dist = (abs(XG - XM) + abs(YG - YM)) * 2; 
    for (ll dx = -max_dist; dx <= max_dist; ++dx) {
        for (ll dy = -max_dist; dy <= max_dist; ++dy) {
            ll distM = abs(dx) + abs(dy);
            ll distG = abs(dx + XM - XG) + abs(dy + YM - YG);
            
            if (7 * distM < 2 * distG) {
                count++;
            }
        }
    }
    cout << count << endl;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}