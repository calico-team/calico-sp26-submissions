#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k, n, m, p, q;
        cin >> k >> n >> m >> p >> q;
        
        int x, y;
        cin >> x >> y;
        
        int origX = x;
        int origY = y;
        
        vector<pair<int, int>> pos;
        for (int i = 0; i < k - 1; i++) {
            int xi, yi;
            cin >> xi >> yi;
            pos.push_back(make_pair(xi, yi));
        }
        
        while (true) {
            bool found = false;
            for (int i = 0; i < k - 1; i++) {
                if (pos[i].first == x && pos[i].second == y) {
                    cout << i + 1 << '\n';
                    found = true;
                    break;
                }
            }
            if (found) break;
            
            x = (x + q) % n;
            y = (y + p) % m;
            
            if (origX == x && origY == y) {
                cout << 0 << '\n';
                break;
            }
        }
    }
}