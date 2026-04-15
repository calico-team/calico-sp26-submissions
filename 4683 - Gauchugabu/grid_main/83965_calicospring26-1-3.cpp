// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    while (n--){
        int t; cin >> t;
        vector<int> v(t);
        for (int i = 0; i < t; i++){
            cin >> v[i];
        }
        vector<int> a(t);
        a[0] = v[0];
        for (int i = 2; i < t; i++){
            if (v[i-2] < v[i-1] && v[i-1] > v[i]){
                if (v[i-2] > v[i]) a[i-1] = v[i-2];
                else a[i-1] = v[i];
            }
            else if (v[i-1] < v[i-2] && v[i-1] < v[i]){
                if (v[i-2] < v[i]) a[i-1] = v[i-2];
                else a[i-1] = v[i];
            }
            else{
                a[i-1] = v[i-1];
            }
        }
        a[t-1] = v[t-1];
        for (int i = 0; i < t; i++){
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}
