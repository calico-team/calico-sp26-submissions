#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t-- >0) {
        int l, w; cin >> l >> w;
        int e, r; cin >> e >> r;

        int lap = r*(2*l + 2*w);

        cout << (int) e/lap << endl;
    }
}