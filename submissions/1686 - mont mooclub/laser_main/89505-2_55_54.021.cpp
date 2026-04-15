#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t-- >0) {
        int k, n, m, p, q; cin >> k >> n >> m >> p >> q;

        int x[k], y[k];

        vector<pair<int, int>> asteroid(n);

        for (int i = 0; i<k; i++) {
            cin >> x[i] >> y[i];
            asteroid[i] = {x[i], y[i]};
        }

        int curx = x[0];
        int cury = y[0];

        bool found = false;

        for (int time = 1; time<=m*n; time++) {
            curx = (curx + q)%n;
            cury = (cury + p)%m;

            for (int i = 0; i<k; i++) {
                if (asteroid[i].first == curx & asteroid[i].second == cury) {
                    cout << i << endl;
                    found = true;
                    break;
                }
            }

            if (found) {
                break;
            }


            
            
        }

        
    }
}