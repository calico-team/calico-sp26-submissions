#include <bits/stdc++.h>
#define f first
#define s second
using ll=long long;
using ull=unsigned long long;
using namespace std;
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n ;
        vector<int> v(n);
        for(int i=0; i<n; i++) cin >> v[i];
        vector<int> b(n);
        for(int i=0; i<n; i++) b[i]=v[i];
        for(int i=0; i<67; i++) {
            for(int j=1; j<n-1; j++) {
                vector<int> tmp={b[j-1], v[j], b[j+1]};
                sort(tmp.begin(), tmp.end());
                b[j]=tmp[1];
            }
            for(int j=n-2; j>=1; j--) {
                vector<int> tmp={b[j-1], v[j], b[j+1]};
                sort(tmp.begin(), tmp.end());
                b[j]=tmp[1];
            }
        }
        for(int i=0; i<n; i++) cout << b[i] << " ";
        cout << "\n";
    }
}