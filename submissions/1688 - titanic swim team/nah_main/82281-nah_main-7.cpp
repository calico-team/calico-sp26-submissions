#include <bits/stdc++.h>
#define f first
#define s second
using ll=long long;
using ull=unsigned long long;
using namespace std;
int main() {
    int t; cin >> t;
    while(t--) {
        int n, p, r, k; cin >> n >> p >> r >> k;
        vector<int> v(n);
        for(int i=0; i<n; i++) cin >> v[i];
        int def=0;
        bool b=true;
        for(int i=0; i<n; i++) {
            p-=v[i];
            def++;
            if(p<0) {
                b=false;
                break;
            }
            if(def%k==0) p+=r;
        }
        if(b) cout << "nah i'd win\n";
        else cout << "nah i'd lose\n";
    }
}