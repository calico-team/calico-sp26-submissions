#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int l, w, e, r;
        cin >> l >> w >> e >> r;

        cout << e / ((l + w) * 2 * r) << '\n';
    }

    return 0;
}