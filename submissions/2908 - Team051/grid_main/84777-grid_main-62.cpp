#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n), b(n);
        for (auto &x : a){ 
            cin >> x;
        }
        b[0] = a[0];
        b[n - 1] = a[n - 1];
        for (int i = 1; i < n - 1; i++) {
            long long L = a[i - 1], R = a[i + 1];
            if ((L <= a[i] && a[i] <= R) || (R <= a[i] && a[i] <= L)){
                b[i] = a[i];
            } 
            else{
                b[i] = min(L, R);
            }
        }
        for (int i = 0; i < n; i++) {
            cout << b[i] << " ";
        }
        cout << '\n';
    }
}