#include <iostream>
using namespace std;

int main() {
    long long t;
    cin >> t;
    while (t--) {
        int l, w, e, r;
        cin >> l >> w >> e >> r;
        int per = 2 * l + 2 * w;
        cout << e / (per * r) << endl;
    }
    
    return 0;
}