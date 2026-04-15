#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int chez[5] = {1, 4, 0, 2, 3};
        int cur = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << chez[(cur + j) % 5] << " ";
            }
            cout << endl;
            cur += 2;
        }
    }
}