#include <bits/stdc++.h>
using namespace std;

int main() {
    // ifstream cin("input");
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a (n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        if (a[n - 1] > a[0]) {
            int most = a[0];
            for (int i = 0; i < n; i++) {
                if (a[i] > most) {
                    most = min(a[i], a[n - 1]);
                }
                cout << most << ' ';
            }
        } else {
            int mini = a[0];
            for (int i = 0; i < n; i++) {
                if (a[i] < mini) {
                    mini = max(a[i], a[n - 1]);
                }
                cout << mini << ' ';
            }
        }
        cout << endl;
    }
}