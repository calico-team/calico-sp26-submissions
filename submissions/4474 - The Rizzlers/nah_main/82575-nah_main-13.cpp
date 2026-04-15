#include <bits/stdc++.h>
using namespace std;


vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, p, r, k;
        cin >> n >> p >> r >> k;
        
        v.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
    
        bool a = true;
        for (int i = 0; i < n; i++) {
            if (i % k == 0 && i != 0) {
                p += r;
            }
            p -= v[i];
            if (p < 0) {
                cout << "nah, i'd lose" << endl;
                a = false;
                break;
            }
        }
        if (a) cout << "nah, i'd win" << endl;
    }
}