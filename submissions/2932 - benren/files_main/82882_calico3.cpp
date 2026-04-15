#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string p, q;
        cin >> p;
        cin >> q;
        
        int j = 0;
        for (int i = 0; i < p.size(); i++) {
            if (j < q.size() && p[i] == q[j]) {
                cout << p[i];
                j++;
            } else {
                cout << '#';
            }
        }
        cout << '\n';
    }
}