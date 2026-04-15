#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t-- >0) {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i<n; i++) {
            cin >> a[i];
        }

        if (n < 3) {
            for (int i = 0; i<n; i++) {
                cout << a[i];
                if (i != n-1) {
                    cout << " ";
                }
            }
        }
        else {
            if ((a[0] < a[1] && a[1] < a[2]) || (a[0] > a[1] && a[1] > a[2])) {
                for (int i = 0; i<n; i++) {
                    cout << a[i];
                    if (i != n-1) {
                        cout << " ";
                    }
                }
            }
            else{
                if (a[1] > a[0]) {
                    if (a[0] > a[2]) {
                        cout << a[0] << " " << a[0] << " " << a[2];
                    }
                    else{
                        cout << a[0] << " " << a[2] << " " << a[2];
                    }
                }
                else {
                    if (a[0] > a[2]) {
                        cout << a[0] << " " << a[2] << " " << a[2];
                    }
                    else{
                        cout << a[0] << " " << a[0] << " " << a[2];
                    }
                }
            }
        }

    }
}