#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int xd(int x1, int x2, int E, int y2) {
    int perimeter = 2 * (x1 + x2);
    int per_lap = perimeter * y2;
    return y1 / per_lap;
}
int main() {
    int T; cin >> T;
    while (T--) {
        int a, b, c, d; 
        cin >> a >> b >> c >> d;
        cout << xd(L, W, E, R) << endl;
    }
    return 0;
}
```