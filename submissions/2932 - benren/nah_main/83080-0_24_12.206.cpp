#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, p, r, k;
        cin >> n >> p >> r >> k;
        
        vector<int> e(n);
        for (int i = 0; i < n; i++) {
            cin >> e[i];
            p -= e[i];
            if (p < 0) {
                cout << "nah i'd lose" << endl;
                break;
            }
            if ((i + 1) % k == 0) p += k;
            if (i == n - 1) cout << "nah i'd win" << endl;
        }
    }
}