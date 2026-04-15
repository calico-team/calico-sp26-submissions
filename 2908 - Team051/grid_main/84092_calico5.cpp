#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<long long> a(n), b(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
            b[i] = a[i];
        }
        for (int i = 1; i + 1 < n; i++){
            if (a[i] > a[i - 1] && a[i] > a[i + 1]){
                b[i] = min(a[i - 1], a[i + 1]);
            }
            else if (a[i] < a[i - 1] && a[i] < a[i + 1]){
                b[i] = max(a[i - 1], a[i + 1]);
            }
        }
        for (int i = 0; i < n; i++){
            cout << b[i] << " " ;
        }
        cout << '\n';
    }
}