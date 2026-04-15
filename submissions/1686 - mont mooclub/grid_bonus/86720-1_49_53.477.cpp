#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t; cin >> t;
    while (t-- >0) {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i<n; i++) {
            cin >> a[i];
        }

        ll diff = 0;

        for (int i = 0; i<n-1; i++) {
            diff += abs(a[i+1]-a[i]);
        }

        int med = a[(n - (n%2))/2];
        
        ll diff2 = 0;
        for (int i = 0; i<n; i++) {
            diff2 += abs(a[i] - med);
        }  

        if (diff < diff2) {
            for (int i = 0; i<n; i++) {
                cout << a[i];
                if (i != n-1) {
                    cout << " ";
                }
            }
            cout << endl;
        }
        else {
            for (int i = 0; i<n; i++) {
                cout << med;
                if (i != n-1) {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
}