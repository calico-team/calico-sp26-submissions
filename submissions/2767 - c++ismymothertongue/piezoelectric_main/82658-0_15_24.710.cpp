#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long long l, w, e, r;
        cin >> l >> w >> e >> r;
        cout << e / (2 * (l + w) * r) << endl;
    }
    return 0;
}
