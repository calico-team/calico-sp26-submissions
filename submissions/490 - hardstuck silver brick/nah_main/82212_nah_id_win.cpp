#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t; cin >> t;
    while (t--) {
        ll n, p, r, k; cin >> n >> p >> r >> k;
        
        ll power = p;
        bool won = true;
        
        for (int i = 0; i < n; i++) {
            ll kapow; cin >> kapow;
            power -= kapow;
            if (power < 0) {
                won = false;
                for (int j = i + 1; j < n; j++) cin >> kapow;
                break;
            }
            if ((i + 1) % k == 0) power += r;
        }
        
        cout << (won ? "nah i'd win" : "nah i'd lose") << endl;
    }
}