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
        }
        if (n == 1){
            cout << a[0] << "\n";
            continue;
        }
        b[0] = a[0];
        b[n-1] = a[n-1];
        for (int i = 1; i < n-1; i++){
            long long L = a[i-1];
            long long R = a[i+1];
            if ((L <= a[i] && a[i] <= R) || (R <= a[i] && a[i] <= L)){
                b[i] = a[i];
            } 
            else{
                if (abs(L - a[i]) < abs(R - a[i])){
                    b[i] = L;
                } 
                else{
                    b[i] = R;
                }
            }
        }
        for (int i = 0; i < n; i++){
            cout << b[i];
            if (i == n-1){
                cout << "\n";
            } 
            else {
                cout << " ";
            }
        }
    }
}