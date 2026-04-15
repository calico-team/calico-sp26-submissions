#include <iostream>
using namespace std;
int main {
    int t; cin >> t;
    while (t--) {
        int h, l, e, r; cin >> h >> l >> e >> r;
        cout << e/(h+l)/2/r;
    }
    return 0;
}