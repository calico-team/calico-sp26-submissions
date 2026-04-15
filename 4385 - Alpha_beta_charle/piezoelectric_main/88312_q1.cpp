#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int l, w, e, r;
        cin >> l >> w >> e >> r;

        int triangle_area = 2 * (l + w);
        int perLap = triangle_area * r;
        int ans = e / perLap;

        cout << ans << endl;
    }

    return 0;
}

void read_your_input() {
}