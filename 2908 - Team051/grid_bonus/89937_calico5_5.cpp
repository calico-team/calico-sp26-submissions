#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        if (n == 1){
            cout << a[0] << "\n";
            continue;
        }
        vector<long long> b = a; 
        bool cambio;
        do{
            cambio = false;
            for (int i = 1; i < n-1; i++){
                long long original_sum = abs(b[i] - b[i-1]) + abs(b[i+1] - b[i]);
                long long nuevo_sum = abs(b[i-1] - b[i+1]);
                if (nuevo_sum < original_sum){
                    b[i] = b[i-1];
                    cambio = true;
                }
            }
        } while (cambio);
        for (int i = 0; i < n; i++){
            cout << b[i];
            if (i == n-1){
                cout << "\n";
            } 
            else{
                cout << " ";
            }
        }
    }
}