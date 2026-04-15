#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        vector<long long> l(n);
        vector<long long> r(n);
        l[0] = a[0];
        r[0] = a[0];
        for(int i = 1; i < n; i++){
            vector<long long> v = {l[i - 1], r[i - 1], a[i], a[i]};
            sort(v.begin(), v.end());
            l[i] = v[1];
            r[i] = v[2];
        }
        vector<long long> b(n);
        b[n - 1] = l[n - 1];
        for(int i = n - 2; i >= 0; i--){
            if(b[i + 1] < l[i]){
                b[i] = l[i];
            }
            else if(b[i + 1] > r[i]){
                b[i] = r[i];
            }
            else{
                b[i] = b[i + 1];
            }
        }
        for(int i = 0; i < n; i++){
            cout << b[i] << " ";
        }
        cout << "\n";
    }
}